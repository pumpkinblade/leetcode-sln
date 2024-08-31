#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int subarraySum(std::vector<int> &nums, int k) {
    int ans = 0;
    std::unordered_map<int, int> map;
    int acc = 0;
    for (int i = 0; i < nums.size(); i++) {
      map[acc] += 1;
      acc += nums[i];
      ans += map[acc - k];
    }
    return ans;
  }
};

int main(void) {
  std::vector<int> nums = {1, -1, 0};
  int k = 0;
  int ans = Solution{}.subarraySum(nums, k);
  std::cout << ans << '\n';
  return 0;
}
