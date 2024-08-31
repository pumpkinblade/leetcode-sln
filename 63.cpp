#include <iostream>
#include <vector>

class Solution {
public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid.front().size();
    std::vector<int> opt(n);
    opt[0] = obstacleGrid[0][0] == 0;
    for (int j = 1; j < n; j++) {
      opt[j] = obstacleGrid[0][j] == 0 ? opt[j - 1] : 0;
    }
    for (int i = 1; i < m; i++) {
      opt[0] = obstacleGrid[i][0] == 0 ? opt[0] : 0;
      for (int j = 1; j < n; j++) {
        opt[j] = obstacleGrid[i][j] == 0 ? (opt[j - 1] + opt[j]) : 0;
      }
    }
    return opt[n - 1];
  }
};

int main(void) {
  std::vector<std::vector<int>> obstacleGrid = {{0, 1}, {0, 0}};
  int res = Solution{}.uniquePathsWithObstacles(obstacleGrid);
  std::cout << res << '\n';
  return 0;
}
