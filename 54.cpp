#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
    std::vector<int> result;
    result.reserve(matrix.size() * matrix.front().size());
    int l = 0, r = matrix.front().size() - 1;
    int t = 0, b = matrix.size() - 1;
    enum { RIGHT, DOWN, LEFT, UP, END } state = RIGHT;
    while (state != END) {
      switch (state) {
      case RIGHT:
        if (l > r)
          state = END;
        else {
          for (int i = l; i <= r; i++) {
            result.push_back(matrix[t][i]);
          }
          t++;
          state = DOWN;
        }
        break;
      case DOWN:
        if (t > b)
          state = END;
        else {
          for (int i = t; i <= b; i++) {
            result.push_back(matrix[i][r]);
          }
          r--;
          state = LEFT;
        }
        break;
      case LEFT:
        if (r < l)
          state = END;
        else {
          for (int i = r; i >= l; i--) {
            result.push_back(matrix[b][i]);
          }
          b--;
          state = UP;
        }
        break;
      case UP:
        if (b < t) {
          state = END;
        } else {
          for (int i = b; i >= t; i--) {
            result.push_back(matrix[i][l]);
          }
          l++;
          state = RIGHT;
        }
        break;
      default:
        break;
      }
    }
    return result;
  }
};

int main(void) {
  std::vector<std::vector<int>> mat = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  std::vector<int> result = Solution{}.spiralOrder(mat);
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
