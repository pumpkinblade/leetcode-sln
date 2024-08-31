#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int>
  longestObstacleCourseAtEachPositionTrivial(std::vector<int> &obstacles) {
    std::vector<int> opt(obstacles.size());
    for (int i = 0; i < obstacles.size(); i++) {
      opt[i] = 1;
      for (int j = 0; j < i; j++) {
        if (obstacles[j] <= obstacles[i]) {
          opt[i] = std::max(opt[i], 1 + opt[j]);
        }
      }
    }
    return opt;
  }

  std::vector<int>
  longestObstacleCourseAtEachPosition(std::vector<int> &obstacles) {
    std::vector<int> res = {1};
    std::vector<int> opt = {obstacles[0]};
    for (int i = 1; i < obstacles.size(); i++) {
      // opt[it-1] <= obstacles[i] < obstacles[it]
      auto it = std::upper_bound(opt.begin(), opt.end(), obstacles[i]);
      if (it == opt.end()) {
        opt.push_back(obstacles[i]);
        res.push_back(opt.size());
      } else {
        *it = obstacles[i];
        res.push_back(std::distance(opt.begin(), it) + 1);
      }
    }
    return res;
  }
};

int main(void) {
  std::vector<int> obstacles = {2, 2, 1};
  std::vector<int> result =
      Solution{}.longestObstacleCourseAtEachPosition(obstacles);
  for (auto x : result) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  return 0;
}
