#pragma once

#include <string>

namespace dualys {

class Command {
public:
  Command();

  // set the futur command to run
  // @param cmd the command to run
  Command *set_command(std::string cmd);

  // execute the command
  int run();

private:
  std::string command;
};
} // namespace dualys
