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

#ifndef BOOT_SHUTDOWN_COMMUNICATION__TOPIC_PUBLISHER_HPP_
#define BOOT_SHUTDOWN_COMMUNICATION__TOPIC_PUBLISHER_HPP_

#include <boost/archive/binary_oarchive.hpp>
#include <boost/asio.hpp>

#include <string>

namespace boot_shutdown_communication
{

template <typename TopicType>
class TopicPublisher
{
public:
  using SharedPtr = std::shared_ptr<TopicPublisher<TopicType>>;

  static SharedPtr create_publisher(
    const std::string & topic_name, boost::asio::io_context & io_context, const std::string & address, unsigned short port)
  {
    return SharedPtr(new TopicPublisher<TopicType>(topic_name, io_context, address, port));
  }

  void publish(const TopicType & message)
  {
    std::ostringstream archive_stream;
    boost::archive::binary_oarchive archive(archive_stream);
    archive << topic_name_;
    archive << message;

    std::string serialized_data = archive_stream.str();
    socket_.send_to(boost::asio::buffer(serialized_data), endpoint_);
  }

private:
  std::string topic_name_;
  boost::asio::ip::udp::socket socket_;
  boost::asio::ip::udp::endpoint endpoint_;

  TopicPublisher(
    const std::string & topic_name, boost::asio::io_context & io_context, const std::string & address, unsigned short port)
  : topic_name_(topic_name),
    socket_(io_context, boost::asio::ip::udp::v4()),
    endpoint_(boost::asio::ip::make_address_v4(address), port)
  {
  }
};

}  // namespace boot_shutdown_communication

#endif  // BOOT_SHUTDOWN_COMMUNICATION__TOPIC_PUBLISHER_HPP_
