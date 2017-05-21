#include <iostream>

#include <useless.h>
#ifdef UPPER
#include <upper.h>
#elif defined(LOWER)
#include <lower.h>
#endif
#include "messages.h"

namespace useless {

void say_hello(const std::string &name) {
  const auto originalMessage = Messages::GREETING + " " + name + "!";
#ifdef UPPER
  const auto finalMessage = upper::to_upper(originalMessage);
#elif defined(LOWER)
  const auto finalMessage = lower::to_lower(originalMessage);
#else
#define finalMessage originalMessage
#endif
  std::cout << finalMessage << std::endl;
}

}
