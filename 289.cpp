#include <iostream>
#include <vector>

class Solution {
public:
  void gameOfLife(std::vector<std::vector<int>> &board) {
    constexpr int dead = 0;
    constexpr int alive = 1;
    constexpr int dying = 2;
    constexpr int resurgent = 3;

    int w = board.front().size();
    int h = board.size();
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int count = 0;
        int i1 = std::max(0, i - 1);
        int i2 = std::min(h, i + 2);
        int j1 = std::max(0, j - 1);
        int j2 = std::min(w, j + 2);
        for (int ii = i1; ii < i2; ii++) {
          for (int jj = j1; jj < j2; jj++) {
            if (ii != i || jj != j)
              count += (board[ii][jj] == alive || board[ii][jj] == dying);
          }
        }
        if ((count < 2 || count > 3) && board[i][j] == alive) {
          board[i][j] = dying;
        }
        if (count == 3 && board[i][j] == dead) {
          board[i][j] = resurgent;
        }
      }
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (board[i][j] == resurgent)
          board[i][j] = alive;
        if (board[i][j] == dying)
          board[i][j] = dead;
      }
    }
  }
};

int main(void) {
  std::vector<std::vector<int>> board = {
      {0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
  Solution{}.gameOfLife(board);
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      std::cout << board[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
