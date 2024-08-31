#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

class Solution {
public:
  int totalNQueens(int n) {
    if (n == 0)
      return 0;
    std::vector<int> col(n);
    int sln = 0;
    std::function<void(int i)> f = [&](int i) {
      if (i == n) {
        sln++;
        return;
      }
      for (int j = 0; j < n; j++) {
        bool safe = true;
        for (int k = 0; k < i && safe; k++) {
          // (i, j) -- (k, col[k])
          safe &= (j != col[k]);
          safe &= (std::abs(i - k) != std::abs(j - col[k]));
        }
        if (safe) {
          col[i] = j;
          f(i + 1);
        }
      }
    };
    f(0);
    return sln;
  }
};

int main(void) {
  int n = 1;
  int sln = Solution{}.totalNQueens(n);
  std::cout << sln << '\n';
  return 0;
}
