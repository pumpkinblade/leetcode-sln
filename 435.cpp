#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                return a.back() < b.back();
              });
    int len = 0;
    int right = std::numeric_limits<int>::min();
    for (const auto &interval : intervals) {
      if (interval.front() >= right) {
        len++;
        right = interval.back();
      }
    }
    return static_cast<int>(intervals.size()) - len;
  }
};
