#include <iostream>

#include <useless.h>
#include <upper.h>
#include "messages.h"

namespace useless {

void say_hello(const std::string &name) {
  const auto message = Messages::GREETING + " " + name + "!";
  std::cout << upper::to_upper(message) << std::endl;
}

}
