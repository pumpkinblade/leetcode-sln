#include <iostream>
#include <vector>

class Solution {
public:
  int bisearch(std::vector<int> nums, int l, int r, int target) {
    while (l <= r) {
      int m = (l + r) / 2;
      if (nums[m] == target)
        return m;
      else if (nums[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }
    return nums[l] == target ? l : -1;
  }

  int search(std::vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (target == nums[m])
        return m;
      if (nums[m] <= nums[r]) {
        if (nums[m] <= target && target <= nums[r])
          return bisearch(nums, m, r, target);
        else
          r = m - 1;
      } else {
        if (nums[l] <= target && target <= nums[m])
          return bisearch(nums, l, m, target);
        else
          l = m + 1;
      }
    }
    return nums[l] == target ? l : -1;
  }
};

int main(void) {
  std::vector<int> nums = {1, 3};
  int target = 3;
  int idx = Solution{}.search(nums, target);
  std::cout << idx << '\n';
  return 0;
}
