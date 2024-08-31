#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int deleteAndEarn(std::vector<int> &nums) {
    std::vector<int> cpy(nums);
    std::sort(cpy.begin(), cpy.end());
    std::vector<std::pair<int, int>> count;
    count.push_back({cpy.front(), 1});
    for (int i = 1; i < cpy.size(); i++) {
      if (cpy[i] == count.back().first) {
        count.back().second++;
      } else {
        count.push_back({cpy[i], 1});
      }
    }

    std::vector<int> opt(count.size());
    opt[0] = count[0].first * count[0].second;
    for (int i = 1; i < opt.size(); i++) {
      int gainOfI = count[i].first * count[i].second;
      int prev = count[i - 1].first + 1 == count[i].first ? i - 2 : i - 1;
      opt[i] = std::max(opt[i - 1], gainOfI + (prev >= 0 ? opt[prev] : 0));
    }
    return opt.back();
  }
};

int main(void) {
  std::vector<int> nums = {2, 2, 3, 3, 3, 4};
  int ans = Solution{}.deleteAndEarn(nums);
  std::cout << ans << '\n';
  return 0;
}
