#include <sstream>

#include <upper.h>

namespace upper {

std::string to_upper(const std::string &input) {
  std::stringstream ss;
  for (const auto item : input)
    ss << static_cast<char>(std::toupper(item));
  return ss.str();
}

}
