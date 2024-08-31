#include <iostream>
#include <vector>

class Solution {
public:
  int lowerBound(std::vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int m = (l + r) / 2;
      if (nums[m] < target) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return l;
  } // return i -> nums[i-1] < target <= nums[i]

  int upperBound(std::vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int m = (l + r) / 2;
      if (nums[m] <= target) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return r;
  } // return i -> nums[i-1] <= target < nums[i]

  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    int lb = lowerBound(nums, target);
    int ub = upperBound(nums, target);
    if (lb < ub)
      return {lb, ub - 1};
    else
      return {-1, -1};
  }
};

int main(void) {
  std::vector<int> nums = {5, 7, 7, 8, 8, 10};
  int target = 6;
  int lb = Solution{}.lowerBound(nums, target);
  std::cout << "lb = " << lb << '\n';
  int ub = Solution{}.upperBound(nums, target);
  std::cout << "ub = " << ub << '\n';
  return 0;
}
