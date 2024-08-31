#include <iostream>
#include <limits>
#include <string>
#include <vector>

class Solution {
public:
  std::string minWindow(std::string s, std::string t) {
    std::vector<int> target(256, 0);
    std::vector<int> hold(256, 0);
    for (auto c : t) {
      target[static_cast<unsigned char>(c)]++;
    }
    auto check = [&]() {
      for (int i = 0; i < target.size(); i++) {
        if (hold[i] < target[i])
          return false;
      }
      return true;
    };

    int p = 0, q = 0;
    int len = std::numeric_limits<int>::max();
    int p1 = 0, q1 = 0;
    while (q < s.size()) {
      hold[static_cast<unsigned char>(s[q])]++;
      q++;
      while (p < q && check()) {
        if (q - p + 1 < len) {
          p1 = p;
          q1 = q;
          len = q - p + 1;
        }
        hold[static_cast<unsigned char>(s[p])]--;
        p++;
      }
    }
    return s.substr(p1, q1 - p1);
  }
};

int main(void) {
  std::string s = "a";
  std::string t = "aa";
  std::string r = Solution{}.minWindow(s, t);
  std::cout << r << '\n';
  return 0;
}
