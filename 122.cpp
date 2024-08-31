#include <iostream>
#include <vector>

class Solution {
public:
  int maxProfitSlow(std::vector<int> &prices) {
    std::vector<int> opt(prices.size() + 1);
    opt[0] = 0;
    for (int i = 1; i <= prices.size(); i++) {
      opt[i] = opt[i - 1];
      for (int j = 1; j < i; j++) {
        opt[i] = std::max(opt[i], opt[j - 1] + prices[i - 1] - prices[j - 1]);
      }
    }
    return opt[prices.size()];
  }

  int maxProfit(std::vector<int> &prices) {
    std::vector<int> free(prices.size());
    std::vector<int> hold(prices.size());
    free[0] = 0;
    hold[0] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
      free[i] = std::max(free[i - 1], hold[i - 1] + prices[i]);
      hold[i] = std::max(hold[i - 1], free[i - 1] - prices[i]);
    }
    return free.back();
  }

  int maxProfixGreedy(std::vector<int> &prices) {
    int val = 0;
    for (int i = 1; i < prices.size(); i++) {
      val += std::max(0, prices[i] - prices[i - 1]);
    }
    return val;
  }
};

int main(void) {
  std::vector<int> prices{7, 1, 5, 3, 6, 4};
  int res = Solution{}.maxProfit(prices);
  std::cout << res << '\n';
  return 0;
}
