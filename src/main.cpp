#include <iostream>

enum E{
  A,B,C
};

#define isinE(x)

int main() {
  std::cout << "Hello world" << std::endl;
  int a;
  std::cin >> a;
  switch (a) {
    case 0:
    case 1:
    default:
      std::cout << "hello";
  }
  return 0;
}