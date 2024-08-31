#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    int i = 1, j = 0;
    for (; i < nums.size(); i++) {
      if (nums[j] != nums[i]) {
        nums[++j] = nums[i];
      }
    }
    return ++j;
  }
};

int main(void) {
  std::vector<int> nums{1, 2, 3, 4};
  auto last = std::unique(nums.begin(), nums.end());
  int k = Solution{}.removeDuplicates(nums);
  for (int i = 0; i < k; i++) {
    std::cout << nums[i] << ' ';
  }
  std::cout << '\n';
}
