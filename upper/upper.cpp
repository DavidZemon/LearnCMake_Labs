#include <sstream>
#if TRACE == 1
#include <iostream>
#endif

#include <upper.h>

namespace upper {

std::string to_upper(const std::string &input) {
  std::stringstream ss;
  for (const auto item : input)
    ss << static_cast<char>(std::toupper(item));
#if TRACE == 1
  std::cout << "[Upper] Finished for-loop" << std::endl;
#endif
  return ss.str();
}

}
