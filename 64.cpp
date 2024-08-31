#include <iostream>
#include <vector>

class Solution {
public:
  int minPathSum(std::vector<std::vector<int>> &grid) {
    int m = grid.size();
    int n = grid.front().size();
    std::vector<int> opt = grid.front();
    for (int j = 1; j < n; j++) {
      opt[j] += opt[j - 1];
    }
    for (int i = 1; i < m; i++) {
      opt[0] += grid[i][0];
      for (int j = 1; j < n; j++) {
        opt[j] = grid[i][j] + std::min(opt[j], opt[j - 1]);
      }
    }
    return opt[n - 1];
  }
};

int main(void) {
  std::vector<std::vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
  int res = Solution{}.minPathSum(grid);
  std::cout << res << '\n';
  return 0;
}
