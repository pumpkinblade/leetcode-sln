#include <functional>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    if (n == 1) {
      result.push_back("()");
      return result;
    }
    auto generated = generateParenthesis(n - 1);
    for (auto &s : generated) {
      result.push_back("()" + s);
    }
    int i = 1, j = n - 2;
    for (; i < j; i++, j--) {
      // (<1>)<n-2>
      // (<2>)<n-3>
      // (<n-2>)<1>
      auto left = generateParenthesis(i);
      auto right = generateParenthesis(j);
      for (auto &l : left) {
        for (auto &r : right) {
          result.push_back("(" + l + ")" + r);
          result.push_back("(" + r + ")" + l);
        }
      }
    }
    if (i == j) {
      auto left = generateParenthesis(i);
      auto right = generateParenthesis(j);
      for (auto &l : left) {
        for (auto &r : right) {
          result.push_back("(" + l + ")" + r);
        }
      }
    }
    for (auto &s : generated) {
      result.push_back("(" + s + ")");
    }
    return result;
  }
};
