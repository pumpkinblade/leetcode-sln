#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int longestValidParenthesesTrivial(std::string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      int x = 0;
      for (int j = i; j < s.size() && x >= 0; j++) {
        x = s[j] == '(' ? x + 1 : x - 1;
        if (x == 0) {
          ans = std::max(ans, j - i + 1);
        }
      }
    }
    return ans;
  }

  int longestValidParentheses(std::string s) {
    // f(i) = {j - i} + f(j) s.t. c[k] - c[i] >= 0 && c[j] - c[i] == 0, any j >
    // i
    int n = s.size();
    std::vector<int> c(n + 1);
    c[0] = 0;
    for (int i = 0; i < n; i++) {
      c[i + 1] = c[i] + (s[i] == '(' ? 1 : -1);
    }
    // c[i] = state of s[0..i)

    std::vector<int> opt(n + 1, 0); // opt[i] = solution of s[i...]
    std::unordered_map<int, int> dp;
    for (int i = n; i >= 0; i--) {
      // find c[i] and c[i] + 1
      if (dp.find(c[i]) != dp.end() && dp.find(c[i] + 1) != dp.end() &&
          dp[c[i]] > dp[c[i] + 1]) {
        opt[i] = opt[dp[c[i]]] + dp[c[i]] - i;
      } else {
        opt[i] = 0;
      }
      dp[c[i]] = i;
    }
    return *std::max_element(opt.begin(), opt.end());
  }
};

int main(void) {
  std::string s = "";
  int ans = Solution{}.longestValidParentheses(s);
  std::cout << ans << '\n';
  return 0;
}
