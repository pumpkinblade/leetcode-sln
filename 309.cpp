#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    std::vector<int> free(prices.size());
    std::vector<int> hold(prices.size());
    std::vector<int> cold(prices.size());
    free[0] = 0;
    hold[0] = -prices[0];
    cold[0] = 0;
    for (int i = 1; i < prices.size(); i++) {
      free[i] = std::max(free[i - 1], cold[i - 1]);
      hold[i] = std::max(hold[i - 1], free[i - 1] - prices[i]);
      cold[i] = hold[i - 1] + prices[i];
    }
    return std::max(free.back(), cold.back());
  }
};
