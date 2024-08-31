#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  int findNumberOfLIS(std::vector<int> &nums) {
    int n = nums.size();
    // opt[i][j] = number of IS with len `j+1` end with nums[i]
    std::vector<int> optLen(n);
    std::vector<int> optCnt(n);
    int maxlen = 1;
    for (int i = 0; i < n; i++) {
      optLen[i] = 1;
      optCnt[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          if (optLen[j] + 1 > optLen[i]) {
            optLen[i] = optLen[j] + 1;
            optCnt[i] = optCnt[j];
          } else if (optLen[j] + 1 == optLen[i]) {
            optCnt[i] += optCnt[j];
          }
        }
      }
      maxlen = std::max(maxlen, optLen[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (optLen[i] == maxlen) {
        ans += optCnt[i];
      }
    }
    return ans;
  }
};

int main(void) {
  std::vector<int> nums = {1, 3, 5, 4, 7};
  int ans = Solution{}.findNumberOfLIS(nums);
  std::cout << ans << '\n';
  return 0;
}
