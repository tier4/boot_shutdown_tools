// Copyright 2024 TIER IV, Inc.
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

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
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
    unsigned short server_port,
    std::chrono::steady_clock::duration timeout_duration = std::chrono::seconds(1))
  {
    return SharedPtr(
      new ServiceClient<ServiceType>(service_name, io_context, server_port, timeout_duration));
  }

  ServiceType call(const ServiceType & service_request)
  {
    std::ostringstream archive_stream;
    boost::archive::binary_oarchive archive(archive_stream);

    archive << service_name_;
    archive << service_request;

    std::string serialized_data = archive_stream.str();
    socket_.send_to(boost::asio::buffer(serialized_data), server_endpoint_);
    std::cout << "Service request sent. " << service_name_ << std::endl;

    return receive_response();
  }

private:
  std::string service_name_;
  unsigned short server_port_;
  boost::asio::io_context & io_context_;
  boost::asio::ip::udp::socket socket_;
  boost::asio::ip::udp::endpoint server_endpoint_;
  std::array<char, 1024> receive_buffer_;
  std::chrono::steady_clock::duration timeout_duration_;

  ServiceClient(
    const std::string & service_name, boost::asio::io_context & io_context,
    unsigned short server_port,
    std::chrono::steady_clock::duration timeout_duration = std::chrono::seconds(1))
  : service_name_(service_name),
    io_context_(io_context),
    socket_(io_context, boost::asio::ip::udp::v4()),
    server_endpoint_(boost::asio::ip::address_v4::broadcast(), server_port),
    timeout_duration_(timeout_duration)
  {
    socket_.set_option(boost::asio::socket_base::broadcast(true));
  }

  ServiceType receive_response()
  {
    boost::system::error_code error;
    std::size_t bytes_transferred = 0;

    boost::asio::steady_timer timer(io_context_);
    timer.expires_after(timeout_duration_);

    receive_buffer_.fill(0);

    bool timeout_occurred = false;

    std::mutex mtx;
    std::condition_variable cv;
    bool data_received = false;

    auto receive_handler = [&](const boost::system::error_code & ec, std::size_t bytes) {
      std::lock_guard<std::mutex> lock(mtx);
      if (!ec) {
        bytes_transferred = bytes;
        data_received = true;
      }
      cv.notify_one();
    };

    socket_.async_receive_from(
      boost::asio::buffer(receive_buffer_), server_endpoint_, receive_handler);

    timer.async_wait([&](const boost::system::error_code & timer_ec) {
      std::lock_guard<std::mutex> lock(mtx);
      if (!data_received) {
        timeout_occurred = true;
        socket_.cancel();
      }
    });

    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [&] { return data_received || timeout_occurred; });

    if (timeout_occurred) {
      throw std::runtime_error("Receive timed out.");
    }

    if (error) {
      throw std::runtime_error("Receive error: " + error.message());
    }

    std::istringstream response_stream(std::string(receive_buffer_.data(), bytes_transferred));
    boost::archive::binary_iarchive response_archive(response_stream);
    ServiceType response;
    response_archive >> response;

    std::cout << "Service response received." << std::endl;
    return response;
  }
};

}  // namespace boot_shutdown_communication

#endif  // BOOT_SHUTDOWN_COMMUNICATION__SERVICE_CLIENT_HPP_
