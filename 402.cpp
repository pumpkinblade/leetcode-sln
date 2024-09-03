#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::string removeKdigits(std::string num, int k) {
    std::vector<char> stk;
    for (int i = 0; i < num.size(); i++) {
      while (k > 0 && !stk.empty() && num[i] < stk.back()) {
        stk.pop_back();
        k--;
      }
      stk.push_back(num[i]);
    }
    while (k > 0 && !stk.empty()) {
      stk.pop_back();
      k--;
    }
    for (int i = 0; i < stk.size(); i++) {
      if (stk[i] != '0') {
        return std::string(stk.begin() + i, stk.end());
      }
    }
    return "0";
  }
};

int main(void) {
  std::string num = "10";
  int k = 2;
  std::string ans = Solution{}.removeKdigits(num, k);
  std::cout << ans << "\n";
  return 0;
}
