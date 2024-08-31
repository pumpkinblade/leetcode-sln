#include <iostream>
#include <vector>

class Solution {
public:
  int maxArea(std::vector<int> &height) {
    // max_{i < j}{ (j - i) * min{x[i], x[j]} }
    int p = 0, q = height.size() - 1;
    int a = (q - p) * std::min(height[p], height[q]);
    while (p < q) {
      while (p < q && height[p] < height[q]) {
        p++;
        a = std::max(a, (q - p) * std::min(height[p], height[q]));
      }
      while (p < q && height[p] >= height[q]) {
        q--;
        a = std::max(a, (q - p) * std::min(height[p], height[q]));
      }
    }
    return a;
  }
};

int main(void) {
  std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int area = Solution{}.maxArea(height);
  std::cout << area << '\n';
  return 0;
}
