#include <functional>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                               int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> buf;
    std::function<void(int, int)> f = [&](int idx, int t) {
      if (t == 0) {
        result.push_back(buf);
        return;
      }
      if (idx == candidates.size())
        return;
      int size = buf.size();
      int num = candidates[idx];
      while (t >= 0) {
        f(idx + 1, t);
        buf.push_back(num);
        t -= num;
      }
      buf.resize(size);
    };
    f(0, target);
    return result;
  }
};
