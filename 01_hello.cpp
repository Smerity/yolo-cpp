// "include" statements are just like import statements in Python
// In C++ you need to include iostream just to get the equivalent of print and raw_input
#include <iostream>

// This is the standard C style main function
// The main function is what is called by default when the program is started
// If you wanted command line arguments, you can get arguments to the program here
int main() {
  // "cout" stands for console output and is just "print"
  // "endl" does two things: newline and "flush"
  // A newline (\n) is actually different across operating systems
  // Flush is a way of saying "Okay, I'm done printing characters, send it to the console"
  std::cout << "Hello world" << std::endl;

  // As is standard for C programs, if everything went fine, return 0, else return non-zero (usually 1)
  return 0;
}
