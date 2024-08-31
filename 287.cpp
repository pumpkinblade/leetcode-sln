#include <iostream>
#include <vector>

class Solution {
public:
  int findDuplicate(std::vector<int> &nums) {
    int n = nums.size();
    int l = 1, r = nums.size();
    while (l < r) {
      int k = (l + r) / 2;
      int lc = 0, mc = 0, rc = 0;

      for (auto x : nums) {
        if (x < k)
          lc++;
        else if (x == k)
          mc++;
        else
          rc++;
      }
      if (mc > 1)
        return k;
      else if (lc > k - 1)
        r = k - 1;
      else
        l = k + 1;
    }
    return l;
  }
};

int main(void) {
  std::vector<int> nums = {3, 3, 3, 3, 3};
  int ans = Solution{}.findDuplicate(nums);
  std::cout << ans << '\n';
  return 0;
}
