#include <vector>

class Solution {
public:
  void sortColors(std::vector<int> &nums) {
    int left = 0, right = nums.size();
    int pivot = 1;
    for (int i = 0; i < right; i++) {
      while (i < right && nums[i] > pivot) {
        std::swap(nums[i], nums[--right]);
      }
      if (nums[i] < pivot) {
        std::swap(nums[i], nums[left++]);
      }
    }
  }
};
