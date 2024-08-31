#include <unordered_map>
#include <vector>

class Solution {
public:
  int findShortestSubArray(std::vector<int> &nums) {
    std::unordered_map<int, std::tuple<int, int, int>> map;
    for (int i = 0; i < nums.size(); i++) {
      auto x = nums[i];
      if (std::get<0>(map[x]) == 0) {
        std::get<1>(map[x]) = i;
      }
      std::get<0>(map[x])++;
      std::get<2>(map[x]) = i;
    }
    int degree = 0;
    int len = 0;
    for (auto [x, d] : map) {
      if (std::get<0>(d) > degree) {
        len = std::get<2>(d) - std::get<1>(d) + 1;
        degree = std::get<0>(d);
      } else if (std::get<0>(d) == degree) {
        len = std::min(len, std::get<2>(d) - std::get<1>(d) + 1);
      }
    }
    return len;
  }
};
