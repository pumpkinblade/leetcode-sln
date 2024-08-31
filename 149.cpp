#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int maxPoints(std::vector<std::vector<int>> &points) {
    int n = points.size();
    int maxlen = std::min(2, n);
    std::vector<std::vector<int>> vs;
    vs.reserve(points.size());
    auto cross = [](const std::vector<int> &u, const std::vector<int> &v) {
      return u.front() * v.back() - u.back() * v.front();
    };
    auto comp = [&](const std::vector<int> &u, const std::vector<int> &v) {
      return cross(u, v) < 0;
    };

    for (int i = 0; i < n - 1; i++) {
      vs.clear();
      for (int j = i + 1; j < n; j++) {
        std::vector<int> v = {points[j].front() - points[i].front(),
                              points[j].back() - points[i].back()};
        if (v.back() < 0) {
          v.front() = -v.front();
          v.back() = -v.back();
        }
        if (v.back() == 0 && v.front() < 0) {
          v.front() = -v.front();
        }
        vs.push_back(v);
      }
      std::sort(vs.begin(), vs.end(), comp);

      int len = 2;
      std::vector<int> u = vs.front();
      for (int k = 1; k < vs.size(); k++) {
        if (cross(u, vs[k]) == 0) {
          len++;
        } else {
          maxlen = std::max(maxlen, len);
          u = vs[k];
          len = 2;
        }
      }
      maxlen = std::max(maxlen, len);
    }
    return maxlen;
  }
};

int main(void) {
  // std::vector<std::vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
  std::vector<std::vector<int>> points = {{1, 1}, {3, 2}, {5, 3},
                                          {4, 1}, {2, 3}, {1, 4}};
  int res = Solution{}.maxPoints(points);
  std::cout << res << '\n';
  return 0;
}
