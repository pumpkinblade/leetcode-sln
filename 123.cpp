#include <iostream>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int n = prices.size();

    std::vector<int> dp(n);
    int accmin = prices[0];
    dp[0] = 0;
    for (int r = 1; r < n; r++) {
      accmin = std::min(accmin, prices[r]);
      dp[r] = std::max(dp[r - 1], prices[r] - accmin);
    }

    int accmax = prices[n - 1];
    int ans = 0;
    int opt = 0;
    for (int l = n - 2; l >= 0; l--) {
      accmax = std::max(accmax, prices[l]);
      opt = std::max(opt, accmax - prices[l]);
      ans = std::max(ans, dp[l] + opt);
    }
    return ans;
  }
};

int main(void) {
  std::vector<int> prices = {1};
  int ans = Solution{}.maxProfit(prices);
  std::cout << ans << '\n';
  return 0;
}
