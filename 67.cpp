#include <iostream>
#include <string>

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    int ls = a.size(), rs = b.size();
    bool carry = false;
    std::string c(std::max(ls, rs) + 1, 0);
    int len = 0;
    while (ls && rs) {
      bool a1 = a[--ls] == '1';
      bool b1 = b[--rs] == '1';
      bool c1 = a1 ^ b1 ^ carry;
      carry = a1 && b1 || a1 && carry || b1 && carry;
      c[len++] = c1 ? '1' : '0';
    }
    while (ls) {
      bool a1 = a[--ls] == '1';
      bool c1 = a1 ^ carry;
      carry = a1 && carry;
      c[len++] = c1 ? '1' : '0';
    }
    while (rs) {
      bool b1 = b[--rs] == '1';
      bool c1 = b1 ^ carry;
      carry = b1 && carry;
      c[len++] = c1 ? '1' : '0';
    }
    if (carry) {
      c[len++] = carry ? '1' : '0';
    }
    c.resize(len);
    for (int i = 0; i < len / 2; i++) {
      std::swap(c[i], c[len - 1 - i]);
    }
    return c;
  }
};

int main(void) {
  std::string a = "11";
  std::string b = "1";
  std::string c = Solution{}.addBinary(a, b);
  std::cout << c << std::endl;
}
