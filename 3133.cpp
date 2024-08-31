#include <iostream>

class Solution {
public:
  long long minEndTrivial(int n, int x) {
    long long res = x;
    while (--n) {
      do {
        res += 1;
      } while ((res & x) != x);
    }
    return res;
  }

  long long minEnd(int n, int x) {
    long long res = x;
    long long shift = x;
    long long bit = 1;
    for (n -= 1; n; n >>= 1) {
      while (shift & 1) {
        bit <<= 1;
        shift >>= 1;
      }
      if (n & 1) {
        res |= bit;
      }
      bit <<= 1;
      shift >>= 1;
    }
    return res;
  }
};

int main(void) {
  int n = 5;
  int x = 4;
  int ans = Solution{}.minEnd(n, x);
  std::cout << ans << '\n';
  return 0;
}
