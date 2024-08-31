#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int longestPalindromeSubseq(std::string s) {
    // f(i, j) = max{f(i+1,j-1), 2 + f(i+1, k-1), 2 + f(l+1, j-1)}
    // s.t. s[i] == s[k] , s[l] == s[j]
    int n = s.size();
    std::vector<std::vector<int>> opt(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
      opt[i][i] = 1;
    }
    for (int d = 1; d < n; d++) {
      // j - i = d && 0 <= i <= n - 1 && 0 <= j <= n -1
      // => std::max(0, -d) <= i <= std::min(n - 1, n - 1 - d)
      for (int i = 0; i <= n - 1 - d; i++) {
        int j = i + d;
        if (s[i] == s[j]) {
          opt[i][j] = 2 + (i + 1 <= j - 1 ? opt[i + 1][j - 1] : 0);
        } else {
          opt[i][j] = std::max(opt[i + 1][j], opt[i][j - 1]);
        }
      }
    }
    return opt[0][n - 1];
  }
};

int main(void) {
  std::string s = "cbbd";
  int ans = Solution{}.longestPalindromeSubseq(s);
  std::cout << ans << '\n';
  return 0;
}
