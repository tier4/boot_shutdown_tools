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

#include "boot_shutdown_interface/boot_shutdown_interface.hpp"

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/process.hpp>

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <syslog.h>
#include <unistd.h>

namespace boot_shutdown_interface
{

/**
 * @brief Print usage
 */
void usage()
{
  printf("Usage: msr_reader [options]\n");
  printf("  -h --help   : Display help\n");
  printf("\n");
}

/**
 * @brief Prepare for shutdown
 */
void prepareShutdown()
{
  syslog(LOG_INFO, "Preparing for shutdown...");
  {
    boost::process::child c("/bin/sh", "-c", "systemctl stop jetson-container.service");
    c.wait();
  }
  {
    boost::process::child c("/bin/sh", "-c", "sync; echo 3 > /proc/sys/vm/drop_caches;");
    c.wait();
  }
}

/**
 * @brief Execute shutdown
 */
void executeShutdown()
{
  syslog(LOG_INFO, "Executing for shutdown...");
  boost::process::child c("/bin/sh", "-c", "shutdown -h now");
  c.wait();
}

/**
 * @brief Run
 */
void run()
{
  remove("/tmp/boot_shutdown");

  // Create a new socket
  int sock = socket(AF_UNIX, SOCK_STREAM, 0);
  if (sock < 0) {
    syslog(LOG_ERR, "Failed to create a new socket. %s\n", strerror(errno));
    return;
  }

  sockaddr_un addr = {};
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, "/tmp/boot_shutdown", sizeof(addr.sun_path) - 1);

  // Give the socket FD the unix domain socket
  int ret = bind(sock, (struct sockaddr *)&addr, sizeof(addr));
  if (ret < 0) {
    syslog(LOG_ERR, "Failed to give the socket FD the unix domain socket. %s\n", strerror(errno));
    close(sock);
    return;
  }

  // Prepare to accept connections on socket FD
  ret = listen(sock, 5);
  if (ret < 0) {
    syslog(LOG_ERR, "Failed to prepare to accept connections on socket FD. %s\n", strerror(errno));
    close(sock);
    return;
  }

  sockaddr_un client = {};
  socklen_t len = sizeof(client);

  while (true) {
    // Await a connection on socket FD
    int new_sock = accept(sock, reinterpret_cast<sockaddr *>(&client), &len);
    if (new_sock < 0) {
      syslog(
        LOG_ERR, "Failed to prepare to accept connections on socket FD. %s\n", strerror(errno));
      close(sock);
      continue;
    }

    // Receive messages from a socket
    char buf[1024] = "";
    ret = recv(new_sock, buf, sizeof(buf) - 1, 0);
    if (ret < 0) {
      close(new_sock);
      continue;
    }
    // No data received
    if (ret == 0) {
      close(new_sock);
      continue;
    }

    ret = close(new_sock);
    if (ret < 0) {
      close(new_sock);
      continue;
    }

    uint8_t request_id = Request::NONE;

    try {
      std::istringstream iss(buf);
      boost::archive::text_iarchive oa(iss);
      oa >> request_id;
    } catch (const std::exception & e) {
      continue;
    }

    switch (request_id) {
      case Request::PREPARE_SHUTDOWN:
        prepareShutdown();
        break;
      case Request::EXECUTE_SHUTDOWN:
        executeShutdown();
        break;
      default:
        break;
    }
  }
}

}  // namespace boot_shutdown_interface

int main(int argc, char ** argv)
{
  static struct option long_options[] = {{"help", no_argument, 0, 'h'}, {0, 0, 0, 0}};

  // Parse command-line options
  int c = 0;
  int option_index = 0;

  while ((c = getopt_long(argc, argv, "hp:", long_options, &option_index)) != -1) {
    switch (c) {
      case 'h':
        boot_shutdown_interface::usage();
        return EXIT_SUCCESS;

      default:
        break;
    }
  }

  // Put the program in the background
  // if (daemon(0, 0) < 0) {
  //  printf("Failed to put the program in the background. %s\n", strerror(errno));
  //  return errno;
  //}

  // Open connection to system logger
  openlog(nullptr, LOG_PID, LOG_DAEMON);

  boot_shutdown_interface::run();

  // Close descriptor used to write to system logger
  closelog();

  return EXIT_SUCCESS;
}
