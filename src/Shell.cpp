#include "../include/Shell.hpp"
#include <iostream>
#include <string>

using namespace dualys;

Shell::Shell() {}

std::string Shell::ask(std::string q, std::string def) {
  std::cout << q;
  std::string l;
  std::getline(std::cin, l);
  return l.empty() ? def : l;
}
int Shell::run() {
  std::string verb;
  do {
    std::cout << "hamon> ";
    verb = ask("");
  } while (verb != "exit");
  return 0;
}
