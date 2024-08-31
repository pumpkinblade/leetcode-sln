
#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  int jump(std::vector<int> &nums) {
    std::vector<int> jn(nums.size(), std::numeric_limits<int>::max());
    jn.front() = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int k = 1; k <= nums[i] && i + k < nums.size(); k++) {
        jn[i + k] = std::min(jn[i + k], jn[i] + 1);
      }
    }
    return jn.back();
  }

  int jumpGreedy(std::vector<int> &nums) {
    int far = 0;
    int end = 0;
    int step = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      far = std::max(far, i + nums[i]);
      if (i == end) {
        end = far;
        step++;
      }
    }
    return step;
  }
};

int main(void) {
  std::vector<int> nums{2, 3, 1, 1, 4};
  int j = Solution{}.jump(nums);
  std::cout << j << '\n';
}
