#include <iostream>
#include <string>

class Solution {
public:
  bool isSubsequence(std::string s, std::string t) {
    int p = 0, q = 0;
    while (p < s.size() && q < t.size()) {
      while (q < t.size() && s[p] != t[q]) {
        q++;
      }
      if (s[p] != t[q])
        return false;
      p++;
      q++;
    }
    return p == s.size();
  }
};

int main(void) {
  std::string s = "axc";
  std::string t = "ahbgdc";
  bool x = Solution{}.isSubsequence(s, t);
  std::cout << std::boolalpha << x << '\n';
}
