#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  int maxEnvelopesTrivial(std::vector<std::vector<int>> &envelopes) {
    std::sort(envelopes.begin(), envelopes.end(),
              [](const std::vector<int> &l, const std::vector<int> &r) {
                return l.front() < r.front();
              });
    std::vector<int> opt(envelopes.size());
    for (int i = 0; i < envelopes.size(); i++) {
      opt[i] = 1;
      for (int j = 0; j < i && envelopes[j].front() < envelopes[i].front();
           j++) {
        if (envelopes[j].back() < envelopes[i].back()) {
          opt[i] = std::max(opt[i], opt[j] + 1);
        }
      }
    }
    return *std::max_element(opt.begin(), opt.end());
  }

  int maxEnvelopes(std::vector<std::vector<int>> &envelopes) {
    std::sort(envelopes.begin(), envelopes.end(),
              [](const std::vector<int> &l, const std::vector<int> &r) {
                return l.front() < r.front();
              });
    std::vector<int> opt(1 + envelopes.size(), std::numeric_limits<int>::max());
    int maxlen = 0;
    opt[maxlen] = 0;
    for (int i = 0; i < envelopes.size();) {
      int x = envelopes[i].front();
      std::vector<std::pair<int, int>> updates;
      for (; i < envelopes.size() && envelopes[i].front() == x; i++) {
        if (envelopes[i].back() > opt[maxlen]) {
          updates.emplace_back(maxlen + 1, envelopes[i].back());
        } else {
          // opt[it-1] < back() <= opt[it]
          auto it = std::lower_bound(opt.begin(), opt.begin() + maxlen + 1,
                                     envelopes[i].back());
          updates.emplace_back(std::distance(opt.begin(), it),
                               envelopes[i].back());
        }
      }
      for (auto [j, y] : updates) {
        maxlen = std::max(maxlen, j);
        opt[j] = std::min(opt[j], y);
      }
    }
    return maxlen;
  }
};

int main(void) {
  std::vector<std::vector<int>> envelopes = {
      {1, 15}, {7, 18}, {7, 6}, {7, 100}, {2, 200}, {17, 30}, {17, 45},
      {3, 5},  {7, 8},  {3, 6}, {3, 10},  {7, 20},  {17, 3},  {17, 45}};
  int ans = Solution{}.maxEnvelopes(envelopes);
  std::cout << ans << '\n';
  return 0;
}
