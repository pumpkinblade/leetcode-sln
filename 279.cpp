#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  int numSquares(int n) {
    std::vector<int> opt(n + 1);
    opt[0] = 0;
    for (int i = 1; i <= n; i++) {
      opt[i] = std::numeric_limits<int>::max();
      for (int j = 1; j * j <= i; j++) {
        opt[i] = std::min(opt[i], 1 + opt[i - j * j]);
      }
    }
    return opt[n];
  }
};

int main(void) {
  std::cout << Solution{}.numSquares(12) << '\n';
  std::cout << Solution{}.numSquares(13) << '\n';
}
