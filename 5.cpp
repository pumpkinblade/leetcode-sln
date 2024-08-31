#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::string longestPalindrome(std::string s) {
    int n = s.size();
    std::vector<std::vector<bool>> opt(n, std::vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
      opt[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++) {
      opt[i][i + 1] = s[i] == s[i + 1];
    }
    for (int k = 2; k < n; k++) {
      for (int i = 0; i < n - k; i++) {
        opt[i][i + k] = s[i] == s[i + k] ? opt[i + 1][i + k - 1] : false;
      }
    }
    int maxlen = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (opt[i][j] && j - i + 1 > maxlen) {
          maxlen = j - i + 1;
          start = i;
        }
      }
    }
    return s.substr(start, maxlen);
  }
};

int main(void) {
  std::string s = "cbbd";
  std::string res = Solution{}.longestPalindrome(s);
  std::cout << res << '\n';
  return 0;
}
