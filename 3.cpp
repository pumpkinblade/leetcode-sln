#include <array>
#include <iostream>
#include <string>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::array<bool, 256> dup;
    for (auto &c : dup) {
      c = false;
    }
    int len = 0;
    int p = 0, q = 0;
    for (; q < s.size(); q++) {
      unsigned char c1 = s[q];
      while (p < q && dup[c1]) {
        unsigned char c2 = s[p];
        dup[c2] = false;
        p++;
      }
      dup[c1] = true;
      len = std::max(len, q - p + 1);
    }
    return len;
  }
};

int main(void) {
  std::string s = "pwwkew";
  int len = Solution{}.lengthOfLongestSubstring(s);
  std::cout << len << '\n';
  return 0;
}
