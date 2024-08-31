#include <iostream>
#include <vector>

class Solution {
public:
  void rotate(std::vector<std::vector<int>> &matrix) {
    int l = 0, r = matrix.size() - 1;
    while (l < r) {
      for (int i = 0; i < r - l; i++) {
        // [l, l] -> [l, r] -> [r, r] -> [r, l] -> [l, l]
        // [l, l+i] -> [l+i, r] -> [r, r-i] -> [r-i, l] -> [l, l+i]
        int tmp = matrix[l][l + i];
        matrix[l][l + i] = matrix[r - i][l];
        matrix[r - i][l] = matrix[r][r - i];
        matrix[r][r - i] = matrix[l + i][r];
        matrix[l + i][r] = tmp;
      }
      l++;
      r--;
    }
  }
};

int main(void) {
  std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution{}.rotate(mat);
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[i].size(); j++) {
      std::cout << mat[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
