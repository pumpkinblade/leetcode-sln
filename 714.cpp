#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices, int fee) {
    int free = 0;
    int hold = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
      free = std::max(free, prices[i] - fee + hold);
      hold = std::max(hold, -prices[i] + free);
    }
    return free;
  }
};
