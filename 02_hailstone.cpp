#include <cassert>
#include <iostream>

// The Hailstone function takes an int and returns at int
int hailstone(int n) {
  // Print out when called so you can see the recursion
  std::cout << n << std::endl;

  // Ensure the number is > 0 (else badness)
  assert(n >= 0);
  // Base case
  if (n == 1)
    return n;
  //
  if (n % 2 == 0) {
    return hailstone(n / 2);
  } else {
    return hailstone((3 * n) + 1);
  }
}

int main() {
  // To define a variable, we have:
  // [type] [name] (optional = [value]);
  int start;
  // "cin" stands for "console in" and knows how to handle the basic types
  std::cin >> start;
  // There are ways of check if everything went fine with "cin"
  // Usually you'll just be lazy though ;)
  if (std::cin.fail()) {
    std::cerr << "Error: non-integer input" << std::endl;
    return 1;
  }
  std::cout << "Calculating Hailstone numbers for n = " << start << std::endl;
  hailstone(start);

  return 0;
}
