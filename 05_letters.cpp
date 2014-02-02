#include <iostream>
#include <fstream>
#include <map>

int main() {
  // Input file
  std::ifstream f;
  f.open("/usr/share/dict/words");
  //
  std::string s;
  std::map<char, int> m;
  //
  std::cout << "Loading words into map" << std::endl;
  while (std::getline(f, s)) {
    // This is a foreach loop from C++-11, not disimilar to Python's "for c in s"
    for(char& c : s) {
      if (c >= 'A' && c <= 'z')
        m[c] += 1;
    }
  }
  for(auto it = m.begin(); it != m.end(); ++it) {
    std::cout << "Letter " << it->first << " has been used " << it->second << " times" << std::endl;
  }

  return 0;
}
