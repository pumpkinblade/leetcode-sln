#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int m = prices[0];
    int p = std::numeric_limits<int>::min();
    for (int i = 1; i < prices.size(); i++) {
      p = std::max(p, prices[i] - m);
      m = std::min(m, prices[i]);
    }
    return std::max(p, 0);
  }
};

int main(void) {
  std::vector<int> prices{7, 6, 4, 3, 1};
  int res = Solution{}.maxProfit(prices);
  std::cout << res << '\n';
  return 0;
}
