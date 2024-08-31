#include <iostream>
#include <vector>

class Solution {
public:
  int largestRectangleArea(std::vector<int> &heights) {
    int n = heights.size();
    int maxArea = 0;
    std::vector<std::pair<int, int>> stk;
    for (int i = 0; i < n; i++) {
      int j = i;
      while (!stk.empty() && stk.back().second >= heights[i]) {
        maxArea = std::max(maxArea, (i - stk.back().first) * stk.back().second);
        j = stk.back().first;
        stk.pop_back();
      }
      stk.push_back({j, heights[i]});
      // for (const auto &[i, h] : stk) {
      //   std::cout << "(" << i << "," << h << ")"
      //             << " ";
      // }
      // std::cout << '\n';
    }
    for (const auto &[i, h] : stk) {
      maxArea = std::max(maxArea, (n - i) * h);
    }
    return maxArea;
  }

  int maximalRectangle(std::vector<std::vector<char>> &matrix) {
    int maxArea = 0;
    int m = matrix.size(), n = matrix.front().size();
    std::vector<int> heights(n, 0);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
      }
      maxArea = std::max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
  }
};

int main(void) {
  // std::vector<std::vector<char>> matrix = {{'1', '0', '1', '0', '0'},
  //                                          {'1', '0', '1', '1', '1'},
  //                                          {'1', '1', '1', '1', '1'},
  //                                          {'1', '0', '0', '1', '0'}};
  std::vector<std::vector<char>> matrix = {{'1', '1'}};
  int area = Solution{}.maximalRectangle(matrix);
  std::cout << area << '\n';
  return 0;
}
