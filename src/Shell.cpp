#include "../include/Shell.hpp"
#include "../include/Make.hpp"
#include <iostream>
#include <ostream>
#include <string>

using namespace dualys;

static void clear_screen() { std::cout << "\033[2J\033[H" << std::flush; }

// Enter alternate screen and pos cursor up left
static void enter_alternate_screen() {
  std::cout << "\033[?1049h\033[2J\033[H" << std::flush;
}

static bool verb_valid(std::string &verb) {
  for (const auto &v : VERBS) {
    if (verb == v) {
      return true;
    }
  }
  return false;
}

static void exit_alternate_screen() {
  std::cout << "\033[?1049l" << std::flush;
}

std::string prompt() { return "\033[1;32mhamon\033[1;37m>\033[0m "; }

Shell::Shell() {}

std::string Shell::ask(std::string q, std::string def) {
  std::cout << q;
  std::string l;
  std::getline(std::cin, l);
  return l.empty() ? def : l;
}

static int execute_verb(std::string &verb) {
  if (verb == VERB_HELP) {
    std::cout << "clear         # clear the screen" << std::endl;
    std::cout << "run $hc_file  # execute the hc commands" << std::endl;
    return SHELL_VERB_EXECUTED_SUCCESS;
  } else if (verb == VERB_CLEAR) {
    clear_screen();
    return SHELL_VERB_EXECUTED_SUCCESS;
  }
  return SHELL_VERB_EXECUTED_FAILURE;
}

int Shell::run() {
  enter_alternate_screen();
  std::string verb;
  do {
    verb = ask(prompt());
    if (!verb_valid(verb)) {
      std::cerr << _("verb not valid type help for help") << std::endl;
      continue;
    } else if (execute_verb(verb) != SHELL_VERB_EXECUTED_SUCCESS) {
      std::cerr << _("An error has been found") << std::endl;
      continue;
    }
  } while (verb != VERB_EXIT);
  exit_alternate_screen();
  return 0;
}
