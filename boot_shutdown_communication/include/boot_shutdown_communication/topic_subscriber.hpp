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

#ifndef BOOT_SHUTDOWN_COMMUNICATION__TOPIC_SUBSCRIBER_HPP_
#define BOOT_SHUTDOWN_COMMUNICATION__TOPIC_SUBSCRIBER_HPP_

#include <boost/archive/binary_oarchive.hpp>
#include <boost/asio.hpp>

#include <string>

namespace boot_shutdown_communication
{

template <typename TopicType>
class TopicSubscriber
{
public:
  using SharedPtr = std::shared_ptr<TopicSubscriber<TopicType>>;
  using SubscriptionCallback = std::function<void(const TopicType &)>;

  static SharedPtr create_subscription(
    const std::string & topic_name, boost::asio::io_context & io_context, unsigned short port,
    SubscriptionCallback subscription_callback)
  {
    static std::once_flag flag;
    std::call_once(
      flag, [&]() { instance_ = SharedPtr(new TopicSubscriber<TopicType>(io_context, port)); });

    instance_->add_subscription(topic_name, subscription_callback);
    return instance_;
  }

private:
  static SharedPtr instance_;
  boost::asio::ip::udp::socket socket_;
  boost::asio::ip::udp::endpoint publisher_endpoint_;
  std::array<char, 1024> receive_buffer_;
  std::map<std::string, SubscriptionCallback> subscriptions_;

  TopicSubscriber(boost::asio::io_context & io_context, unsigned short port) : socket_(io_context)
  {
    socket_.open(boost::asio::ip::udp::v4());

    socket_.set_option(boost::asio::socket_base::reuse_address(true));
    socket_.bind(boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port));

    receive();
  }

  void add_subscription(const std::string & topic_name, SubscriptionCallback subscription_callback)
  {
    subscriptions_[topic_name] = subscription_callback;
  }

  void receive()
  {
    socket_.async_receive_from(
      boost::asio::buffer(receive_buffer_), publisher_endpoint_,
      [&](boost::system::error_code ec, std::size_t bytes_recvd) {
        if (!ec && bytes_recvd > 0) {
          std::string received_data(receive_buffer_.data(), bytes_recvd);
          std::istringstream archive_stream(received_data);
          boost::archive::binary_iarchive archive(archive_stream);

          std::string topic_name;
          TopicType topic;
          try {
            archive >> topic_name;
            archive >> topic;
          } catch (const std::exception & e) {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cerr << "Failed to read topic from archive." << std::endl;
          }

          auto callback = subscriptions_.find(topic_name);
          if (callback != subscriptions_.end()) {
            callback->second(topic);
          }
        }

        receive();
      });
  }
};

template <typename TopicType>
typename TopicSubscriber<TopicType>::SharedPtr TopicSubscriber<TopicType>::instance_ = nullptr;

}  // namespace boot_shutdown_communication

#endif  // BOOT_SHUTDOWN_COMMUNICATION__TOPIC_SUBSCRIBER_HPP_
