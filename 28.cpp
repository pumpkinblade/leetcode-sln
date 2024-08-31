#include <iostream>
#include <string>

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    return haystack.find(needle);
  }
};

int main(void) {
  std::string haystack = "sadbutsad";
  std::string needle = "sad";
  int idx = Solution{}.strStr(haystack, needle);
  std::cout << idx << '\n';
  return 0;
}
