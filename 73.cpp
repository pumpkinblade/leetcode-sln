#include <vector>

class Solution {
public:
  void setZeroes(std::vector<std::vector<int>> &matrix) {
    bool firstRowZero = false;
    for (int j = 0; j < matrix[0].size(); j++) {
      if (matrix[0][j] == 0) {
        firstRowZero = true;
      }
    }
    for (int i = 1; i < matrix.size(); i++) {
      bool rowZero = false;
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == 0) {
          rowZero = true;
          matrix[0][j] = 0;
        }
      }
      if (rowZero) {
        for (int j = 0; j < matrix[i].size(); j++) {
          matrix[i][j] = 0;
        }
      }
    }
    for (int j = 0; j < matrix[0].size(); j++) {
      if (matrix[0][j] == 0) {
        for (int i = 0; i < matrix.size(); i++) {
          matrix[i][j] = 0;
        }
      }
    }
    if (firstRowZero) {
      for (int j = 0; j < matrix[0].size(); j++) {
        matrix[0][j] = 0;
      }
    }
  }
};
