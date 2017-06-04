#include <useless.h>
#include <reverse.h>

int main() {
  const std::string reversed = reverse("David");
  useless::say_hello(reversed);
  return 0;
}
