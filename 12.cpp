#include <iostream>
#include <sstream>
#include <string>

class Solution {
public:
  std::string intToRoman(int num) {
    std::ostringstream oss;

    int k = num / 1000;
    for (int i = 0; i < k; i++)
      oss << 'M';
    num %= 1000;

    int h = num / 100;
    if (h == 9) {
      oss << "CM";
      h -= 9;
    }
    if (h >= 5) {
      oss << 'D';
      h -= 5;
    }
    if (h == 4) {
      oss << "CD";
      h -= 4;
    }
    for (int i = 0; i < h; i++)
      oss << 'C';
    num %= 100;

    h = num / 10;
    if (h == 9) {
      oss << "XC";
      h -= 9;
    }
    if (h >= 5) {
      oss << 'L';
      h -= 5;
    }
    if (h == 4) {
      oss << "XL";
      h -= 4;
    }
    for (int i = 0; i < h; i++)
      oss << 'X';
    num %= 10;

    h = num;
    if (h == 9) {
      oss << "IX";
      h -= 9;
    }
    if (h >= 5) {
      oss << 'V';
      h -= 5;
    }
    if (h == 4) {
      oss << "IV";
      h -= 4;
    }
    for (int i = 0; i < h; i++)
      oss << 'I';
    return oss.str();
  }
};

int main(void) {
  int num = 3749;
  std::string s = Solution{}.intToRoman(num);
  std::cout << s << '\n';
  return 0;
}
