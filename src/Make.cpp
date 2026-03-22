#include "../include/Make.hpp"
#include <filesystem>
#include <string>

using namespace dualys;
namespace fs = std::filesystem;

int Make::build_from_hc(const std::string &hc_path) {
  if (!fs::exists(hc_path)) {
    std::cerr << "The hamon cube file : " << hc_path << " has not been found"
              << std::endl;
    return HC_FILE_NOT_EXISTS;
  }
  if (hc_path.rfind(".hc") == std::string::npos) {
    std::cerr << _("All hamon cube file must be have the hc extension")
              << std::endl;
    return FILE_NOT_HC;
  }
  return HC_FILE_EXECUTED_SUCCESS;
}
