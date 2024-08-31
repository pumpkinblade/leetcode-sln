#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int minimumDeleteSum(std::string s1, std::string s2) {
    int m = s1.size(), n = s2.size();
    std::vector<std::vector<int>> opt(m + 1, std::vector<int>(n + 1));
    opt[0][0] = 0;
    for (int j = 1; j <= n; j++) {
      opt[0][j] = opt[0][j - 1] + s2[j - 1];
    }
    for (int i = 1; i <= m; i++) {
      opt[i][0] = opt[i - 1][0] + s1[i - 1];
      for (int j = 1; j <= n; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          opt[i][j] = opt[i - 1][j - 1];
        } else {
          opt[i][j] =
              std::min(s1[i - 1] + opt[i - 1][j], s2[j - 1] + opt[i][j - 1]);
        }
      }
    }
    return opt[m][n];
  }
};

int main(void) {
  std::string s1 = "delete";
  std::string s2 = "leet";
  int ans = Solution{}.minimumDeleteSum(s1, s2);
  std::cout << ans << '\n';
  return 0;
}
