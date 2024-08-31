#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int minFallingPathSum(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    if (n == 1)
      return matrix.front().front();

    std::vector<int> opt = matrix.front();
    std::vector<int> opt2(n);
    for (int i = 1; i < n; i++) {
      opt2[0] = matrix[i][0] + std::min(opt[0], opt[1]);
      for (int j = 1; j < n - 1; j++) {
        opt2[j] =
            matrix[i][j] + std::min(std::min(opt[j - 1], opt[j]), opt[j + 1]);
      }
      opt2[n - 1] = matrix[i][n - 1] + std::min(opt[n - 1], opt[n - 2]);
      opt.swap(opt2);
    }
    return *std::min_element(opt.begin(), opt.end());
  }
};

int main(void) {
  std::vector<std::vector<int>> matrix = {{-19, 57}, {-40, -5}};
  int ans = Solution{}.minFallingPathSum(matrix);
  std::cout << ans << '\n';
  return 0;
}
