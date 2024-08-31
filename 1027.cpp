#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int longestArithSeqLength(std::vector<int> &nums) {
    int m = *std::min_element(nums.begin(), nums.end());
    int M = *std::max_element(nums.begin(), nums.end());
    int maxD = M - m;
    int ans = std::min(2, static_cast<int>(nums.size()));
    for (int d = -maxD; d <= maxD; d++) {
      std::unordered_map<int, int> opt;
      for (auto x : nums) {
        if (opt.find(x - d) != opt.end()) {
          opt[x] = std::max(opt[x], opt[x - d] + 1);
        } else {
          opt[x] = std::max(opt[x], 1);
        }
        ans = std::max(ans, opt[x]);
      }
    }
    return ans;
  }
};
