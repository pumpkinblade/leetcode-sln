#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int numDistinct(std::string s, std::string t) {
    constexpr int M = 1000000007;
    int m = s.size(), n = t.size();
    std::vector<std::vector<int>> opt(m + 1, std::vector<int>(n + 1));
    opt[0][0] = 1;
    for (int j = 1; j <= n; j++) {
      opt[0][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
      opt[i][0] = 1;
      for (int j = 1; j <= std::min(i, n); j++) {
        opt[i][j] = s[i - 1] == t[j - 1] ? opt[i - 1][j - 1] : 0;
        opt[i][j] = (opt[i][j] + opt[i - 1][j]) % M;
      }
      for (int j = i + 1; j <= n; j++) {
        opt[i][j] = 0;
      }
    }
    return opt[m][n];
  }
};

int main(void) {
  std::string s = "rabbbit";
  std::string t = "rabbit";
  int ans = Solution{}.numDistinct(s, t);
  std::cout << ans << '\n';
  return 0;
}
