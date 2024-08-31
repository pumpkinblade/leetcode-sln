#include <cstring>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> result;
    if (digits.size() == 0)
      return result;
    static const char *digitLetterMap[] = {"abc", "def",  "ghi", "jkl",
                                           "mno", "pqrs", "tuv", "wxyz"};
    std::string buf(' ', digits.size());
    std::function<void(int)> f = [&](int idx) {
      if (idx == digits.size())
        result.emplace_back(buf.c_str(), digits.size());
      else {
        char c = digits[idx];
        const char *s = digitLetterMap[c - '2'];
        while (*s) {
          buf[idx] = *s;
          f(idx + 1);
          s++;
        }
      }
    };
    f(0);
    return result;
  }
};
