#include <iomanip>
#include <iostream>
#include <string>

class Solution {
public:
  std::string reverseWords(std::string s) {
    int n = -1;
    bool d = false;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ' ') {
        if (d) {
          s[++n] = ' ';
        }
        s[++n] = s[i];
        d = false;
      } else {
        d = n >= 0;
      }
    }
    ++n;

    for (int i = 0; i < n / 2; i++) {
      std::swap(s[i], s[n - 1 - i]);
    }

    int p = 0, q = 0;
    while (p < n) {
      q = p + 1;
      while (q < n && s[q] != ' ') {
        q++;
      }
      for (int i = 0; i < (q - p) / 2; i++) {
        std::swap(s[p + i], s[q - 1 - i]);
      }
      p = q + 1;
    }
    return s.substr(0, n);
  }
};

int main(void) {
  std::string s1 = "a good   example";
  std::string s2 = Solution{}.reverseWords(s1);
  std::cout << std::quoted(s2) << '\n';
  return 0;
}
