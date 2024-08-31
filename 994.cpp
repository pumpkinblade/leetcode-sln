#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
  int orangesRotting(std::vector<std::vector<int>> &grid) {
    int m = grid.size(), n = grid.front().size();
    int fresh = 0;
    int minute = 0;
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          fresh++;
        } else if (grid[i][j] == 2) {
          q.push({i, j});
        }
      }
    }

    while (fresh && !q.empty()) {
      minute++;
      int s = q.size();
      while (s--) {
        auto [i, j] = q.front();
        q.pop();

        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
          fresh--;
          grid[i - 1][j] = 2;
          q.push({i - 1, j});
        }
        if (i + 1 < m && grid[i + 1][j] == 1) {
          fresh--;
          grid[i + 1][j] = 2;
          q.push({i + 1, j});
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
          fresh--;
          grid[i][j - 1] = 2;
          q.push({i, j - 1});
        }
        if (j + 1 < n && grid[i][j + 1] == 1) {
          fresh--;
          grid[i][j + 1] = 2;
          q.push({i, j + 1});
        }
      }
    }
    if (fresh == 0)
      return minute;
    return -1;
  }
};

int main(void) {
  std::vector<std::vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  auto ans = Solution{}.orangesRotting(grid);
  std::cout << ans << '\n';
  return 0;
}
