#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Solution {
public:
  std::string convert(std::string s, int numRows) {
    if (numRows == 1)
      return s;

    int n = s.size();
    std::ostringstream oss;
    int l = 2 * (numRows - 1);

    for (int i = 0; i < n; i += l) {
      oss << s[i];
    }
    for (int r = 1; r < numRows - 1; r++) {
      int i = r;
      int offset = 2 * (numRows - 1 - r);
      for (; i + offset < n; i += l) {
        oss << s[i];
        oss << s[i + offset];
      }
      if (i < n)
        oss << s[i];
    }
    for (int i = numRows - 1; i < n; i += l) {
      oss << s[i];
    }
    return oss.str();
  }
};

int main(void) {
  std::string s = "PAYPALISHIRING";
  int numRows = 3;
  std::string zs = Solution{}.convert(s, numRows);
  std::cout << std::quoted(zs) << '\n';
  std::cout << zs.size() << '\n';
  return 0;
}
