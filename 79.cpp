#include <functional>
#include <string>
#include <vector>

class Solution {
public:
  bool exist(std::vector<std::vector<char>> &board, std::string word) {
    int m = board.size();
    int n = board[0].size();
    std::vector<std::vector<bool>> mark(m, std::vector<bool>(n, false));
    std::function<bool(int, int, int)> f = [&](int i, int j, int p) {
      if (board[i][j] != word[p])
        return false;
      if (p + 1 == word.size())
        return true;
      mark[i][j] = true;
      if (i - 1 >= 0 && !mark[i - 1][j] && f(i - 1, j, p + 1))
        return true;
      if (i + 1 < m && !mark[i + 1][j] && f(i + 1, j, p + 1))
        return true;
      if (j - 1 >= 0 && !mark[i][j - 1] && f(i, j - 1, p + 1))
        return true;
      if (j + 1 < n && !mark[i][j + 1] && f(i, j + 1, p + 1))
        return true;
      mark[i][j] = false;
      return false;
    };

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (f(i, j, 0))
          return true;
      }
    }
    return false;
  }
};
