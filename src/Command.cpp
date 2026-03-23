#include "../include/Command.hpp"
#include <cstdio>
#include <string>

using namespace dualys;

Command::Command() {}

Command *Command::set_command(std::string cmd) {
  this->command.clear();
  this->command.append(cmd);
  return this;
}

int Command::run() {
  FILE *fp = popen(this->command.c_str(), "w");
  if (!fp) {
    return 1;
  }
  return pclose(fp);
}
