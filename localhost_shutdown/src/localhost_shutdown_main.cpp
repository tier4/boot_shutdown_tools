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

#include "localhost_shutdown/localhost_shutdown.hpp"

#include <errno.h>
#include <getopt.h>
#include <string.h>
#include <unistd.h>

void usage()
{
  printf("Usage: localhost_shutdown [options]\n");
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

  const std::string default_config_yaml_path = "/etc/localhost_shutdown/localhost_shutdown.param.yaml";
  std::string config_yaml_path = default_config_yaml_path;

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

  localhost_shutdown::LocalhostShutdown shutdown(config_yaml_path);

  shutdown.initialize();
  shutdown.run();

  return EXIT_SUCCESS;
}
