#include <functional>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> result;
    std::vector<int> buf(k);
    std::function<void(int, int)> f = [&](int idx, int start) {
      if (idx == k)
        result.push_back(buf);
      else {
        for (int i = start; i <= n; i++) {
          buf[idx] = i;
          f(idx + 1, i + 1);
        }
      }
    };
    f(0, 1);
    return result;
  }
};
