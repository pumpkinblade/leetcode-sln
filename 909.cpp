#include <iostream>
#include <queue>
#include <vector>
class Solution {
public:
  int snakesAndLadders(std::vector<std::vector<int>> &board) {
    int n = board.size();
    auto idxToCoord = [&](int idx) {
      int i = n - 1 - idx / n;
      int j = (n - 1 - i) & 1 ? n - 1 - idx % n : idx % n;
      return std::make_pair(i, j);
    };
    auto nextOf = [&](int idx) {
      auto [i, j] = idxToCoord(idx);
      if (board[i][j] == -1) {
        return idx;
      } else {
        return board[i][j] - 1;
      }
    };
    std::vector<int> mark(n * n, false);
    std::queue<std::pair<int, int>> queue;
    int target = n * n - 1;
    queue.push({0, 0});
    mark[0] = true;
    while (!queue.empty()) {
      auto [idx, len] = queue.front();
      queue.pop();
      if (idx == target)
        return len;
      for (int idx2 = idx + 1; idx2 <= std::min(idx + 6, target); idx2++) {
        int next = nextOf(idx2);
        if (!mark[next]) {
          queue.push({next, len + 1});
          mark[next] = true;
        }
      }
    }
    return -1;
  }
};

int main(void) {
  // std::vector<std::vector<int>> board = {
  //     {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
  //     {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
  //     {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
  // std::vector<std::vector<int>> board = {{-1, -1}, {-1, 3}};
  // std::vector<std::vector<int>> board = {{-1, -1, -1}, {-1, 9, 8}, {-1, 8,
  // 9}};
  // std::vector<std::vector<int>> board = {{1, 1, -1}, {1, 1, 1}, {-1, 1, 1}};
  std::vector<std::vector<int>> board = {
      {-1, -1, -1, 46, 47, -1, -1, -1}, {51, -1, -1, 63, -1, 31, 21, -1},
      {-1, -1, 26, -1, -1, 38, -1, -1}, {-1, -1, 11, -1, 14, 23, 56, 57},
      {11, -1, -1, -1, 49, 36, -1, 48}, {-1, -1, -1, 33, 56, -1, 57, 21},
      {-1, -1, -1, -1, -1, -1, 2, -1},  {-1, -1, -1, 8, 3, -1, 6, 56}};
  int res = Solution{}.snakesAndLadders(board);
  std::cout << res << '\n';
  return 0;
}
