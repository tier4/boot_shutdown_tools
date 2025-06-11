// Copyright 2022-2025 TIER IV, Inc.
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
#include <unistd.h>

void usage()
{
  printf("Usage: boot_shutdown_service [options]\n");
  printf("  -h --help   : Display help\n");
  printf("  -c --config : Configuration yaml file path\n");
  printf("\n");
}

int main(int argc, char ** argv)
{
  static struct option long_options[] = {
    {"help", no_argument, 0, 'h'}, {"config", required_argument, nullptr, 'c'}, {0, 0, 0, 0}};

  int c = 0;
  int option_index = 0;
  std::string config_yaml_path;

  while ((c = getopt_long(argc, argv, "hc:", long_options, &option_index)) != -1) {
    switch (c) {
      case 'h':
        usage();
        return EXIT_SUCCESS;

      case 'c':
        config_yaml_path = optarg;
        break;

      default:
        break;
    }
  }

  boot_shutdown_service::BootShutdownService service(config_yaml_path);

  if (!service.initialize()) {
    return EXIT_FAILURE;
  }

  service.run();

  service.shutdown();

  return EXIT_SUCCESS;
}
