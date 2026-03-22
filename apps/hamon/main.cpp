#include "../../include/Make.hpp"
#include "../../include/Shell.hpp"
#include <cxxopts.hpp>
#include <iostream>
#include <string>

#define VERSION "0.0.0"

#ifndef I18N_GETTEXT_DEFINED
#define _(String) gettext(String)
#define I18N_GETTEXT_DEFINED
#endif

using namespace dualys;

static int version() {
  std::cout << _("hamon version : ") << VERSION << std::endl;
  return 0;
}
int main(const int argc, char **argv) {

  cxxopts::Options options("hamon", "A distributed computing framework");
  options.add_options()("s,shell", "run hamon shell")(
      "r,run", "Execute task in  the hc file", cxxopts::value<std::string>())(
      "h,help", "Print usage")("v,version", "Print version");

  auto r = options.parse(argc, argv);

  if (r.count("help")) {
    std::cout << options.help() << std::endl;
    return 0;
  }
  if (r.count("version")) {
    return version();
  }
  if (r.count("shell")) {
    return (new Shell())->run();
  }
  if (r.count("run")) {
    std::string hc = r["run"].as<std::string>();
    if (hc.rfind(".hc") == std::string::npos) {
      std::cerr << _("hamon support only hc file") << std::endl;
      return FILE_NOT_HC;
    }
    return Make::build_from_hc(hc);
  }
  return 0;
}
