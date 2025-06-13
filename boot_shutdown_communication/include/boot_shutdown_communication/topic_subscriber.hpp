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

#ifndef BOOT_SHUTDOWN_COMMUNICATION__TOPIC_SUBSCRIBER_HPP_
#define BOOT_SHUTDOWN_COMMUNICATION__TOPIC_SUBSCRIBER_HPP_

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
        if (ec) {
          std::cerr << "Receive error: " << ec.message() << std::endl;
          return;
        }
        if (bytes_recvd == 0) {
          std::cerr << "No data received" << std::endl;
          receive();
          return;
        }

        std::string received_data(receive_buffer_.data(), bytes_recvd);
        TopicType topic;

        if (topic.ParseFromString(received_data)) {
          auto callback = subscriptions_.find(topic.header().name());
          if (callback != subscriptions_.end()) {
            callback->second(topic);
          }
        } else {
          std::cerr << "Failed to parse received protobuf data" << std::endl;
        }

        receive();
      });
  }
};

template <typename TopicType>
typename TopicSubscriber<TopicType>::SharedPtr TopicSubscriber<TopicType>::instance_ = nullptr;

}  // namespace boot_shutdown_communication

#endif  // BOOT_SHUTDOWN_COMMUNICATION__TOPIC_SUBSCRIBER_HPP_
