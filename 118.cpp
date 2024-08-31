#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> tri;
    tri.push_back({1});
    for (int i = 1; i < numRows; i++) {
      tri.emplace_back();
      tri[i].push_back(1);
      for (int j = 1; j <= i - 1; j++) {
        tri[i].push_back(tri[i - 1][j - 1] + tri[i - 1][j]);
      }
      tri[i].push_back(1);
    }
    return tri;
  }
};
