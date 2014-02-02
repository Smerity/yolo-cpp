#include <iostream>

// Pass by value
// Any changes in here disappear
void squareA(int n) {
  n = n * n;
}

// Pass by pointer (C style)
// You get the address of the variable
// To modify it requires the asterisk
void squareB(int *n) {
  *n = *n * *n;
}

// Pass by reference (C++)
// Similar to above but no asterisk required
void squareC(int &n) {
  n = n * n;
}

int main() {
  int v = 3;

  std::cout << v << std::endl;

  squareA(v);
  std::cout << v << std::endl;

  squareB(&v);
  std::cout << v << std::endl;

  v = 3;
  squareC(v);
  std::cout << v << std::endl;

  return 0;
}
