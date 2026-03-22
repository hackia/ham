#pragma once

#include <string>

namespace dualys {
class Shell {
public:
  // Constructor
  Shell();
  // Run the shell
  int run();
  // Ask user and return response
  std::string ask(std::string q, std::string def = {});
};
} // namespace dualys
