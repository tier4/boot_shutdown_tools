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

#include "boot_shutdown_service/boot_shutdown_service.hpp"

#include <errno.h>
#include <getopt.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>

/**
 * @brief Print usage
 */
void usage()
{
  printf("Usage: msr_reader [options]\n");
  printf("  -h --help   : Display help\n");
  printf("  -s --socket # : Path of UNIX domain socket.\n");
  printf("\n");
}

int main(int argc, char ** argv)
{
  static struct option long_options[] = {
    {"help", no_argument, 0, 'h'}, {"socket", required_argument, nullptr, 's'}, {0, 0, 0, 0}};

  // Parse command-line options
  int c = 0;
  int option_index = 0;
  std::string socket_path = boot_shutdown_service::SOCKET_PATH;

  while ((c = getopt_long(argc, argv, "hs:", long_options, &option_index)) != -1) {
    switch (c) {
      case 'h':
        usage();
        return EXIT_SUCCESS;

      case 's':
        socket_path = optarg;
        break;

      default:
        break;
    }
  }

  // Put the program in the background
  if (daemon(0, 0) < 0) {
    printf("Failed to put the program in the background. %s\n", strerror(errno));
    return errno;
  }

  // Open connection to system logger
  openlog(nullptr, LOG_PID, LOG_DAEMON);

  // Initialize boot/shutdown service
  boot_shutdown_service::BootShutdownService service(socket_path);

  if (!service.initialize()) {
    service.shutdown();
    closelog();
    return EXIT_FAILURE;
  }

  // Run main loop
  service.run();

  // Shutdown boot/shutdown service
  service.shutdown();

  // Close descriptor used to write to system logger
  closelog();

  return EXIT_SUCCESS;
}
