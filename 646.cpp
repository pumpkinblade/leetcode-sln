#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int findLongestChain(std::vector<std::vector<int>> &pairs) {
    std::vector<std::vector<int>> cpy(pairs);
    auto comp = [](const std::vector<int> &l, const std::vector<int> &r) {
      return l.front() < r.front();
    };
    std::sort(cpy.begin(), cpy.end(), comp);

    std::vector<int> opt(cpy.size());
    opt[cpy.size() - 1] = 1;
    for (int i = cpy.size() - 2; i >= 0; i--) {
      // cpy[it-1].front() <= cpy[i].back() < cpy[it].front()
      auto it = std::upper_bound(cpy.begin() + i, cpy.end(),
                                 std::vector<int>{cpy[i].back(), 0}, comp);
      if (it == cpy.end()) {
        opt[i] = 1;
      } else {
        opt[i] = 1 + opt[std::distance(cpy.begin(), it)];
      }
      opt[i] = std::max(opt[i], opt[i + 1]);
    }
    return *std::max_element(opt.begin(), opt.end());
  }
};

int main(void) {
  std::vector<std::vector<int>> pairs = {{7, 9},  {4, 5},  {7, 9}, {-7, -1},
                                         {0, 10}, {3, 10}, {3, 6}, {2, 3}};
  int ans = Solution{}.findLongestChain(pairs);
  std::cout << ans << '\n';
  return 0;
}
