#include <limits>
#include <stack>
#include <vector>

class Solution {
public:
  bool increasingTriplet(std::vector<int> &nums) {
    int m1 = nums.front();
    int m2 = std::numeric_limits<int>::max();
    for (auto x : nums) {
      if (x > m2) {
        return true;
      } else if (x > m1) {
        m2 = std::min(m2, x);
      } else {
        m1 = std::min(m1, x);
      }
    }
    return false;
  }
};
