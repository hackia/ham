#include "../include/Shell.hpp"
#include <iostream>
#include <string>

using namespace dualys;

static void enter_alternate_screen() {
  std::cout << "\033[?1049h\033[2J\033[H" << std::flush;
}

static void exit_alternate_screen() {
  std::cout << "\033[?1049l" << std::flush;
}

Shell::Shell() {}

std::string Shell::ask(std::string q, std::string def) {
  std::cout << q;
  std::string l;
  std::getline(std::cin, l);
  return l.empty() ? def : l;
}
int Shell::run() {
  enter_alternate_screen();
  std::string verb;
  do {
    std::cout << "\033[1;32mhamon\033[1;37m>\033[0m ";
    verb = ask("");
  } while (verb != "exit");
  exit_alternate_screen();
  return 0;
}
