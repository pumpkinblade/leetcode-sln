#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int minDistance(std::string word1, std::string word2) {
    int m = word1.size(), n = word2.size();
    std::vector<std::vector<int>> opt(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++) {
      opt[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
      opt[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        int d = word1[i - 1] == word2[j - 1] ? opt[i - 1][j - 1]
                                             : 1 + opt[i - 1][j - 1];
        d = std::min(d, 1 + opt[i][j - 1]);
        d = std::min(d, 1 + opt[i - 1][j]);
        opt[i][j] = d;
      }
    }
    return opt[m][n];
  }
};

int main(void) {
  std::string word1 = "";
  std::string word2 = "ros";
  int res = Solution{}.minDistance(word1, word2);
  std::cout << res << '\n';
  return 0;
}
