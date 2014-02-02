#include <cassert>
#include <iostream>

void example_static() {
  // This is only ever created once and will be incremented each time the function is called
  static unsigned int count = 0;
  std::cout << "This function has been called " << ++count << " times" << std::endl;
}

unsigned long long int fib(int n) {
  assert(n >= 0);
  if (n < 2)
    return n;
  return fib(n - 1) + fib(n - 2);
}

unsigned long long int memo_fib(int n) {
  static unsigned long long int results[90] = {};

  assert(n >= 0);
  assert(n <= 90);
  if (n < 2)
    return n;

  if (results[n] == 0) {
    results[n] = memo_fib(n - 1) + memo_fib(n - 2);
  }
  return results[n];
}

int main() {
  std::cout << "=== Standard Fibonacci ===" << std::endl;
  for (int n = 0; n < 42; n++) {
    std::cout << "Calculating fib(" << n << "): " << fib(n) << std::endl;
  }

  std::cout << "=== Memoized Fibonacci ===" << std::endl;
  for (int n = 0; n < 90; n++) {
    std::cout << "Calculating memo_fib(" << n << "): " << memo_fib(n) << std::endl;
  }

  std::cout << "=== Display example_static's behaviour ===" << std::endl;
  example_static();
  example_static();
  example_static();

  return 0;
}
