#pragma once

#include <iosfwd>
#include <iostream>
#include <libintl.h>
#include <string>

#ifndef I18N_GETTEXT_DEFINED
#define _(String) gettext(String)
#define I18N_GETTEXT_DEFINED
#endif

// All task has been successfully executed
#define HC_FILE_EXECUTED_SUCCESS 0

// A task or tasks has been a failure
#define HC_FILE_EXECUTED_FAILURE 1

// The given filename not exist
#define HC_FILE_NOT_EXISTS 2

// The given filename have not the hc file extension
#define FILE_NOT_HC 3

using namespace std;

namespace dualys {
struct CursorGuard {
  CursorGuard() { std::cout << "\033[?25l" << std::flush; }
  ~CursorGuard() { std::cout << "\033[?25h" << std::flush; }
};

class Make {
public:
  // Execute all task from hamon cube file
  static int build_from_hc(const std::string &hc_path);
};
} // namespace dualys
