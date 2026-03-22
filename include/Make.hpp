#pragma once

#include <iosfwd>
#include <iostream>
#include <libintl.h>
#include <string>

#ifndef I18N_GETTEXT_DEFINED
#define _(String) gettext(String)
#define I18N_GETTEXT_DEFINED
#endif

#define HC_FILE_EXISTS 0
#define HC_FILE_NOT_EXISTS 1

using namespace std;

namespace dualys {
struct CursorGuard {
  CursorGuard() { std::cout << "\033[?25l" << std::flush; }
  ~CursorGuard() { std::cout << "\033[?25h" << std::flush; }
};

// A very small helper to "build hamon by hamon" using a .hc script.
// It scans @phase lines and executes the task="..." commands in order.
// Notes:
// - Uses HamonParser to pre-parse the file so that variable expansion ${VAR}
//   defined via @let works before executing tasks.
// - Job/topology directives are not orchestrated here yet; this is a local
// runner.
// - Designed to be easily extended to support language extensions later.
class Make {
public:
  // Parse the given .hc file and execute its task commands sequentially.
  // Returns true on success (all commands returned exit code 0), false
  // otherwise.
  static int build_from_hc(const std::string &hc_path);
};
} // namespace dualys
