#include <exception>
#include <iostream>
#include <string>

#include "foo.h"

int foo() { return -1; }

int main(int argc, char* argv[]) {
  const int expected = (argc > 1) ? std::stoi(argv[1]) : 12346;
  const int result = bar();
  if (result == expected) {
    return 0;
  } else {
    std::cout << "bar() returns " << result << ", expected: " << expected
              << std::endl;
    std::terminate();
  }
}
