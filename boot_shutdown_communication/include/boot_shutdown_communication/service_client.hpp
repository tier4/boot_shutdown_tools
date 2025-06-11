// Copyright 2024-2025 TIER IV, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef BOOT_SHUTDOWN_COMMUNICATION__SERVICE_CLIENT_HPP_
#define BOOT_SHUTDOWN_COMMUNICATION__SERVICE_CLIENT_HPP_

#include "boot_shutdown_communication/utility.hpp"

#include <boost/asio.hpp>

#include <iostream>

namespace boot_shutdown_communication
{

template <typename ServiceType>
class ServiceClient
{
public:
  using SharedPtr = std::shared_ptr<ServiceClient<ServiceType>>;

  static SharedPtr create_client(
    const std::string & service_name, boost::asio::io_context & io_context,
    const std::string & service_address, unsigned short service_port,
    int timeout = std::chrono::seconds(1))
  {
    return SharedPtr(new ServiceClient<ServiceType>(
      service_name, io_context, service_address, service_port, timeout));
  }

  std::shared_ptr<ServiceType> call(ServiceType & service_request)
  {
    set_header(service_request, service_name_);

    std::string serialized_data;

    if (!service_request.SerializeToString(&serialized_data)) {
      std::cerr << "Failed to serialize message: " << service_name_ << std::endl;
      return nullptr;
    }

    socket_.send_to(boost::asio::buffer(serialized_data), server_endpoint_);
    std::cout << "Service request sent: " << service_name_ << "," << service_address_ << ":"
              << service_port_ << std::endl;

    return receive_response();
  }

private:
  std::string service_name_;
  unsigned short service_port_;
  boost::asio::ip::udp::socket socket_;
  boost::asio::ip::udp::endpoint server_endpoint_;
  std::array<char, 1024> receive_buffer_;
  std::string service_address_;
  int timeout_;
  boost::asio::steady_timer timer_;
  boost::asio::io_context & io_context_;

  ServiceClient(
    const std::string & service_name, boost::asio::io_context & io_context,
    const std::string & service_address, unsigned short service_port, int timeout)
  : service_name_(service_name),
    socket_(io_context, boost::asio::ip::udp::v4()),
    server_endpoint_(boost::asio::ip::make_address_v4(service_address), service_port),
    service_address_(service_address),
    service_port_(service_port),
    timeout_(timeout),
    timer_(io_context),
    io_context_(io_context)
  {
  }

  std::shared_ptr<ServiceType> receive_response()
  {
    boost::system::error_code error_code;
    std::size_t bytes_transferred = 0;

    timer_.expires_after(std::chrono::seconds(timeout_));

    socket_.async_receive_from(
      boost::asio::buffer(receive_buffer_), server_endpoint_,
      [&](const boost::system::error_code & ec, std::size_t bytes) {
        error_code = ec;
        bytes_transferred = bytes;
        timer_.cancel();
      });

    timer_.async_wait([&](const boost::system::error_code & ec) {
      if (!ec) {
        socket_.cancel();
      }
    });

    while (bytes_transferred == 0 && !error_code) {
      io_context_.run_one();
    }

    if (error_code) {
      throw std::runtime_error("Receive error: " + error_code.message());
    }

    std::string received_data(receive_buffer_.data(), bytes_transferred);
    auto response = std::make_shared<ServiceType>();

    if (!response->ParseFromString(received_data)) {
      throw std::runtime_error("Failed to parse received protobuf data");
    }

    std::cout << "Service response received" << std::endl;
    std::cout << response->DebugString() << std::endl;
  
    return response;
  }
};

}  // namespace boot_shutdown_communication

#endif  // BOOT_SHUTDOWN_COMMUNICATION__SERVICE_CLIENT_HPP_
