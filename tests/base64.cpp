#include <iostream>
#include "../inc/base64.h"

int main() {
  auto base64 = libspu::to_base64("Hello, World!");
  std::cout << base64 << '\n'; // SGVsbG8sIFdvcmxkIQ==

  auto s = libspu::from_base64("SGVsbG8sIFdvcmxkIQ==");
  std::cout << s << '\n'; // Hello, World!
}