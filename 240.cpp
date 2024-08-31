#include <algorithm>
#include <vector>

class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix.front().size();
    for (int i = 0; i < m; i++) {
      auto it = std::lower_bound(matrix[i].begin(), matrix[i].end(), target);
      if (it != matrix[i].end() && *it == target)
        return true;
    }
    return false;
  }
};
