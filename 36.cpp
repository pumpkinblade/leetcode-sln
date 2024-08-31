#include <array>
#include <vector>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {
    std::array<unsigned int, 27> masks; // 0-9: hori, 10-18: vert, 19-27: block
    for (auto &m : masks)
      m = 0;

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char c = board[i][j];
        if (c == '.')
          continue;

        unsigned int bit = 1 << (c - '0');
        if (masks[i] & bit)
          return false;
        masks[i] |= bit;
        if (masks[9 + j] & bit)
          return false;
        masks[9 + j] |= bit;
        if (masks[18 + i / 3 * 3 + j / 3] & bit)
          return false;
        masks[18 + i / 3 * 3 + j / 3] |= bit;
      }
    }

    return true;
  }
};
