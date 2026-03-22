#pragma once
#include <string>
namespace dualys {
class Shell {
public:
  Shell();
  int run();
  std::string ask(std::string q, std::string def = {});
};
} // namespace dualys
