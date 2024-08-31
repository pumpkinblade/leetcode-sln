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
};

int main(void) {
  std::vector<int> heights = {2, 4};
  int ans = Solution{}.largestRectangleArea(heights);
  std::cout << ans << '\n';
  return 0;
}
