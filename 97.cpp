#include <cstring>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    int m = s1.size();
    int n = s2.size();
    if (s3.size() != m + n)
      return false;
    if (s1.size() == 0) {
      return s2 == s3;
    }
    if (s2.size() == 0) {
      return s1 == s3;
    }
    std::vector<std::vector<bool>> opt(m + n, std::vector<bool>(m + 1, false));
    opt[m + n - 1][m - 1] = s3[m + n - 1] == s1[m - 1];
    opt[m + n - 1][m] = s3[m + n - 1] == s2[n - 1];
    for (int ij = m + n - 2; ij >= 0; ij--) {
      // ij = i + j
      // 0 <= i <= m && 0 <= j <= n -> 0 <= ij - i <= n
      // -> ij - n <= i <= ij
      for (int i = std::max(0, ij - n); i <= std::min(m, ij); i++) {
        int j = ij - i;
        // match s3[ij...ij+k-1] with s1[i...i+k-1]
        // -> ij + k < m + n && i + k < m
        for (int k = 1; k <= std::min(m + n - ij, m - i) && !opt[ij][i]; k++) {
          if (strncmp(s3.c_str() + ij, s1.c_str() + i, k) == 0 &&
              opt[ij + k][i + k]) {
            opt[ij][i] = true;
          }
        }
        // match s3[ij...ij+k-1] with s2[j...j+k-1]
        // -> ij + k < m + n && j + k < n
        for (int k = 1; k <= std::min(m + n - ij, n - j) && !opt[ij][i]; k++) {
          if (strncmp(s3.c_str() + ij, s2.c_str() + j, k) == 0 &&
              opt[ij + k][i]) {
            opt[ij][i] = true;
          }
        }
      }
    }
    return opt[0][0];
  }
};

int main(void) {
  std::string s1 = "";
  std::string s2 = "";
  std::string s3 = "";
  bool res = Solution{}.isInterleave(s1, s2, s3);
  std::cout << std::boolalpha << res << '\n';
  return 0;
}
