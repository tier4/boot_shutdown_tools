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

#ifndef BOOT_SHUTDOWN_COMMUNICATION__SERVICE_SERVER_HPP_
#define BOOT_SHUTDOWN_COMMUNICATION__SERVICE_SERVER_HPP_

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/asio.hpp>

#include <iostream>

namespace boot_shutdown_communication
{

template <typename ServiceType>
class ServiceServer
{
public:
  using SharedPtr = std::shared_ptr<ServiceServer<ServiceType>>;
  using RequestCallback = std::function<void(const ServiceType &, ServiceType &)>;

  static SharedPtr create_service(
    const std::string & service_name, boost::asio::io_context & io_context,
    unsigned short service_port, RequestCallback request_callback)
  {
    return SharedPtr(
      new ServiceServer<ServiceType>(service_name, io_context, service_port, request_callback));
  }

private:
  std::string service_name_;
  boost::asio::ip::udp::socket socket_;
  boost::asio::ip::udp::endpoint client_endpoint_;
  std::array<char, 1024> receive_buffer_;
  RequestCallback request_callback_;

  ServiceServer(
    const std::string & service_name, boost::asio::io_context & io_context,
    unsigned short service_port, RequestCallback request_callback)
  : service_name_(service_name),
    socket_(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), service_port)),
    request_callback_(request_callback)
  {
    receive();
  }

  void receive()
  {
    receive_buffer_.fill(0);

    socket_.async_receive_from(
      boost::asio::buffer(receive_buffer_), client_endpoint_,
      [this](const boost::system::error_code & error_code, std::size_t bytes_transferred) {
        if (!error_code) {
          std::istringstream archive_stream(std::string(receive_buffer_.data(), bytes_transferred));
          boost::archive::binary_iarchive archive(archive_stream);

          std::string service_name;
          ServiceType request;
          ServiceType response;
          try {
            archive >> service_name;
            archive >> request;
          } catch (const std::exception & e) {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cerr << "Failed to read service from archive." << std::endl;
            send_response(response);
          }

          std::cout << "Received request: " << service_name << std::endl;

          if (service_name == service_name_) {
            request_callback_(request, response);
            send_response(response);
          }

          receive();
        } else {
          std::cerr << "Receive error: " << error_code.message() << std::endl;
        }
      });
  }

  void send_response(const ServiceType & response)
  {
    std::ostringstream archive_stream;
    boost::archive::binary_oarchive archive(archive_stream);
    archive << response;
    std::string serialized_data = archive_stream.str();

    socket_.async_send_to(
      boost::asio::buffer(serialized_data), client_endpoint_,
      [](const boost::system::error_code & error, std::size_t /*bytes_transferred*/) {
        if (error) {
          std::cerr << "Send error: " << error.message() << std::endl;
        } else {
          std::cout << "Response sent." << std::endl;
        }
      });
  }
};

}  // namespace boot_shutdown_communication

#endif  // BOOT_SHUTDOWN_COMMUNICATION__SERVICE_SERVER_HPP_
