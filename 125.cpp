#include <cctype>
#include <iostream>
#include <string>

class Solution {
public:
  bool isPalindrome(std::string s) {
    int p = 0, q = s.size() - 1;
    while (p < q) {
      while (p < q && !std::isalnum(s[p]))
        p++;
      while (p < q && !std::isalnum(s[q]))
        q--;
      if (p < q && std::tolower(s[p]) != std::tolower(s[q]))
        return false;
      p++;
      q--;
    }
    return true;
  }
};

int main(void) {
  std::string s = " ";
  bool x = Solution{}.isPalindrome(s);
  std::cout << std::boolalpha << x << '\n';
}
