// Copyright 2022 TIER IV, Inc.
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

#include "boot_shutdown_interface/service/boot_shutdown_service.hpp"

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/process.hpp>

#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <syslog.h>

namespace boot_shutdown_interface
{

  BootShutdownService::BootShutdownService(const std::string &socket_path) : socket_path_(socket_path), socket_(-1), connection_(-1) {}

  bool BootShutdownService::initialize()
  {
    // Remove previous binding
    remove(socket_path_.c_str());

    // Create a new socket
    socket_ = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socket_ < 0)
    {
      syslog(LOG_ERR, "Failed to create a new socket. %s\n", strerror(errno));
      return false;
    }

    sockaddr_un addr = {};
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, socket_path_.c_str(), sizeof(addr.sun_path) - 1);

    // Give the socket FD the unix domain socket
    int ret = bind(socket_, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0)
    {
      syslog(LOG_ERR, "Failed to give the socket FD the unix domain socket. %s\n", strerror(errno));
      shutdown();
      return false;
    }

    // Prepare to accept connections on socket FD
    ret = listen(socket_, 5);
    if (ret < 0)
    {
      syslog(LOG_ERR, "Failed to prepare to accept connections on socket FD. %s\n", strerror(errno));
      shutdown();
      return false;
    }

    return true;
  }

  void BootShutdownService::shutdown() { close(socket_); }

  void BootShutdownService::run()
  {
    sockaddr_un client = {};
    socklen_t len = sizeof(client);

    while (true)
    {
      // Await a connection on socket FD
      connection_ = accept(socket_, reinterpret_cast<sockaddr *>(&client), &len);
      if (connection_ < 0)
      {
        syslog(
            LOG_ERR, "Failed to prepare to accept connections on socket FD. %s\n", strerror(errno));
        close(connection_);
        continue;
      }

      // Receive messages from a socket
      char buffer[1024]{};
      int ret = recv(connection_, buffer, sizeof(buffer) - 1, 0);
      if (ret < 0)
      {
        syslog(LOG_ERR, "Failed to recv. %s\n", strerror(errno));
        close(connection_);
        continue;
      }
      // No data received
      if (ret == 0)
      {
        syslog(LOG_ERR, "No data received.\n");
        close(connection_);
        continue;
      }

      // Handle message
      handleMessage(buffer);

      close(connection_);
    }
  }

  void BootShutdownService::handleMessage(const char *buffer)
  {
    uint8_t request_id = Request::NONE;

    // Restore request from ros node
    try
    {
      std::istringstream in_stream(buffer);
      boost::archive::text_iarchive archive(in_stream);
      archive >> request_id;
    }
    catch (const std::exception &e)
    {
      syslog(LOG_ERR, "Failed to restore message. %s\n", e.what());
      return;
    }

    switch (request_id)
    {
    case Request::PREPARE_SHUTDOWN:
      prepareShutdown();
      break;
    case Request::EXECUTE_SHUTDOWN:
      executeShutdown();
      break;
    case Request::IS_READY_TO_SHUTDOWN:
      isReadyToShutdown();
      break;
    default:
      syslog(LOG_WARNING, "Unknown message. %d\n", request_id);
      break;
    }
  }

  void BootShutdownService::prepareShutdown()
  {
    is_ready_ = false;

    syslog(LOG_INFO, "Preparing for shutdown...");

    std::thread thread([this]
                       {
    {
      boost::process::child c("/bin/sh", "-c", "systemctl stop jetson-container.service");
      c.wait();
    }
    {
      boost::process::child c("/bin/sh", "-c", "sync; echo 3 > /proc/sys/vm/drop_caches;");
      c.wait();
    }

    std::lock_guard<std::mutex> lock(mutex_);
    is_ready_ = true; });

    thread.detach();
  }

  void BootShutdownService::executeShutdown()
  {
    syslog(LOG_INFO, "Executing for shutdown...");

    std::thread thread([this]
                       {
    boost::process::child c("/bin/sh", "-c", "shutdown -h now");
    c.wait(); });

    thread.detach();
  }

  void BootShutdownService::isReadyToShutdown()
  {
    bool is_ready = false;
    {
      std::lock_guard<std::mutex> lock(mutex_);
      is_ready = is_ready_;
    }

    // Inform ros node
    std::ostringstream out_stream;
    boost::archive::text_oarchive archive(out_stream);
    archive << Request::IS_READY_TO_SHUTDOWN;
    archive << is_ready;

    //  Write N bytes of BUF to FD
    int ret = write(connection_, out_stream.str().c_str(), out_stream.str().length());
    if (ret < 0)
    {
      syslog(LOG_ERR, "Failed to write N bytes of BUF to FD. %s\n", strerror(errno));
    }
  }

} // namespace boot_shutdown_interface
