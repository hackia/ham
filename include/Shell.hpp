#pragma once

#include <string>
#include <vector>

#ifndef I18N_GETTEXT_DEFINED
#define _(String) gettext(String)
#define I18N_GETTEXT_DEFINED
#endif

// command for exit shell
const std::string VERB_EXIT = "exit";
// command for clear screen
const std::string VERB_CLEAR = "clear";
// command for display help
const std::string VERB_HELP = "help";
// All shell commands
const std::vector<std::string> VERBS = {VERB_EXIT, VERB_HELP, VERB_CLEAR};

namespace dualys {
class Shell {
public:
  // Constructor
  Shell();
  // Run the shell
  int run();
  // Ask user and return response
  // @param q the question
  // @param def the default response
  // @return response
  std::string ask(std::string q, std::string def = {});
};
} // namespace dualys
