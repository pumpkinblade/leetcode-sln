#include <iostream>
#include <vector>

class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    int i = 0, j = 0;
    for (; i != nums.size(); i++) {
      if (nums[i] != val) {
        nums[j++] = nums[i];
      }
    }
    nums.resize(j);
    return j;
  }
};

int main(void) {
  std::vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;
  int k = Solution{}.removeElement(nums, val);
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << '\n';
  std::cout << "k = " << k << '\n';
  return 0;
}
