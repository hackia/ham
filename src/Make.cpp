#include "../include/Make.hpp"
#include <filesystem>
#include <string>

using namespace dualys;

int Make::build_from_hc(const std::string &hc_path) {
  if (std::filesystem::exists(hc_path)) {
    return HC_FILE_EXISTS;
  }
  return HC_FILE_NOT_EXISTS;
}
