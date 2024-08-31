#include <iostream>
#include <vector>

class Solution {
public:
  int coinChange(std::vector<int> &coins, int amount) {
    std::vector<int> lookup(amount + 1, -1);
    lookup.front() = 0;
    for (int i = 1; i <= amount; i++) {
      int m = -1;
      for (int j : coins) {
        if (j <= i && lookup[i - j] >= 0) {
          m = m == -1 ? 1 + lookup[i - j] : std::min(m, 1 + lookup[i - j]);
        }
      }
      lookup[i] = m;
    }
    return lookup.back();
  }
};

int main(void) {
  std::vector<int> coins = {1};
  int amount = 0;
  int res = Solution{}.coinChange(coins, amount);
  std::cout << res << '\n';
  return 0;
}
