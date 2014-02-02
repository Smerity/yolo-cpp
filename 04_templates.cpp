#include <algorithm>
#include <iostream>
#include <vector>

template <class T> bool compare(T a, T b) {
  return a < b;
}

int main() {
  std::vector<int> v;
  v.push_back(42);
  v.push_back(8);
  v.push_back(16);
  v.push_back(128);

  // Note: Sort doesn't need compare for simple data types (i.e. ints)
  // It's useful to see how you could write custom comparators though
  std::sort(v.begin(), v.end(), &compare<int>);

  // "auto" is a C++-11 feature and works out the type
  // Otherwise it would be std::vector<int>::iterator... Eww...
  for(auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << std::endl;
  }

  return 0;
}
