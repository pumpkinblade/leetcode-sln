#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int trap(std::vector<int> &height) {
    int n = height.size();
    int n1 = std::distance(height.begin(),
                           std::max_element(height.begin(), height.end()));
    int res = 0;
    for (int i = 1, h = height[0]; i < n1; i++) {
      if (height[i] > h) {
        h = height[i];
      } else {
        res += h - height[i];
      }
    }
    for (int i = n - 2, h = height[n - 1]; i > n1; i--) {
      if (height[i] > h) {
        h = height[i];
      } else {
        res += h - height[i];
      }
    }
    return res;
  }
};

int main(void) {
  std::vector<int> height{4, 2, 0, 3, 2, 5};
  int res = Solution{}.trap(height);
  std::cout << res << '\n';
}
