#include <functional>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> buf(nums);
    std::function<void(int)> f = [&, n = nums.size()](int idx) {
      if (idx == n)
        result.push_back(buf);
      else {
        for (int i = idx; i < n; i++) {
          std::swap(buf[idx], buf[i]);
          f(idx + 1);
          std::swap(buf[idx], buf[i]);
        }
      }
    };
    f(0);
    return result;
  }
};
