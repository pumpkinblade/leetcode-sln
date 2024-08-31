#include <algorithm>
#include <functional>
#include <vector>

class Solution {
public:
  std::vector<int> findOrder(int numCourses,
                             std::vector<std::vector<int>> &prerequisites) {
    std::vector<std::vector<int>> cpy(prerequisites);
    auto comp = [](const std::vector<int> &left,
                   const std::vector<int> &right) {
      return left.front() < right.front();
    };
    std::sort(cpy.begin(), cpy.end(), comp);

    bool loop = false;
    std::vector<int> res;
    constexpr int WHITE = 0;
    constexpr int GRAY = 1;
    constexpr int BLACK = 2;
    std::vector<int> color(numCourses);
    std::function<void(int)> dfs = [&](int u) {
      color[u] = GRAY;
      auto it =
          std::lower_bound(cpy.begin(), cpy.end(), std::vector<int>{u, 0});
      for (; it != cpy.end() && it->front() == u; it++) {
        if (color[it->back()] == WHITE) {
          dfs(it->back());
        }
        if (color[it->back()] == GRAY) {
          loop = true;
        }
      }
      color[u] = BLACK;
      res.push_back(u);
    };

    for (int u = 0; u < numCourses; u++) {
      if (color[u] == WHITE) {
        dfs(u);
      }
    }

    return loop ? std::vector<int>{} : res;
  }
};
