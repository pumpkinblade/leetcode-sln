#include <string>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    int p = 0;
    while (true) {
      if (p >= strs.front().size()) {
        break;
      }
      char c = strs.front()[p];
      int i = 1;
      for (; i < strs.size(); i++) {
        if (p >= strs[i].size() || strs[i][p] != c)
          break;
      }
      if (i < strs.size())
        break;
      p++;
    }

    return strs.front().substr(0, p);
  }
};
