#include <iostream>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    int i = 1, j = 0, k = 0;
    for (; i < nums.size(); ++i) {
      if (nums[j] == nums[i]) {
        if (k) {
          continue;
        } else {
          k = 1;
        }
      } else {
        k = 0;
      }
      nums[++j] = nums[i];
    }
    return ++j;
  }
};

int main(void) {
  std::vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};
  int k = Solution{}.removeDuplicates(nums);
  for (int i = 0; i < k; i++) {
    std::cout << nums[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
