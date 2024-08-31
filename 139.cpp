#include <cstring>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
    int n = s.size();
    int m = wordDict.size();
    std::vector<bool> success(n + 1, true);
    for (int i = 1; i <= n; i++) {
      // try match s[0,i)
      int j = 0;
      for (; j < m; j++) {
        const auto &word = wordDict[j];
        int k = word.size();
        // match s[i - k + 1, i]
        if (k <= i && success[i - k] &&
            std::strncmp(s.c_str() + i - k, word.c_str(), k) == 0)
          break;
      }
      success[i] = j < m;
    }
    // for (int i = 0; i <= n; i++)
    //   std::cout << std::boolalpha << success[i] << ' ';
    // std::cout << '\n';
    return success.back();
  }
};

int main(void) {
  std::string s = "leetcode";
  std::vector<std::string> workDict = {"leet", "ode"};
  bool res = Solution{}.wordBreak(s, workDict);
  std::cout << std::boolalpha << res << '\n';
  return 0;
}
