#include <lower.h>

#include <sstream>

namespace lower {

std::string to_lower(const std::string &input) {
  std::stringstream ss;
  for (const auto item : input)
    ss << static_cast<char>(std::tolower(item));
  return ss.str();
}

}
