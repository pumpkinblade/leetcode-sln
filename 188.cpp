#include <vector>

class Solution {
public:
  int maxProfit(int k, std::vector<int> &prices) {
    std::vector<int> buy(k + 1);
    std::vector<int> sell(k + 1);
    for (int j = 1; j <= k; j++) {
      buy[j] = -prices[0];
      sell[j] = 0;
    }
    for (int i = 1; i < prices.size(); i++) {
      // buy[1] = max{buy[1], -prices[i]}
      // sell[1] = max{sell[1], prices[i] + buy[1]}
      // buy[2] = max{buy[2], sell[1] - prices[i]}
      // sell[2] = max{sell[2], prices[i] + buy[2]}
      // ...
      buy[1] = std::max(buy[1], -prices[i]);
      for (int j = 1; j <= k - 1; j++) {
        sell[j] = std::max(sell[j], buy[j] + prices[i]);
        buy[j + 1] = std::max(buy[j + 1], sell[j] - prices[i]);
      }
      sell[k] = std::max(sell[k], buy[k] + prices[i]);
    }

    return sell[k];
  }
};
