#include <cassert>
#include <cstring>
#include <iostream>
#include <string>

class Solution {
public:
  int romanToInt(std::string s) {
    int num = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      switch (s[i]) {
      case 'I':
        if (i + 1 < n && s[i + 1] == 'V') {
          i++;
          num += 4;
        } else if (i + 1 < n && s[i + 1] == 'X') {
          i++;
          num += 9;
        } else {
          num += 1;
        }
        break;
      case 'V':
        num += 5;
        break;
      case 'X':
        if (i + 1 < n && s[i + 1] == 'L') {
          i++;
          num += 40;
        } else if (i + 1 < n && s[i + 1] == 'C') {
          i++;
          num += 90;
        } else {
          num += 10;
        }
        break;
      case 'L':
        num += 50;
        break;
      case 'C':
        if (i + 1 < n && s[i + 1] == 'D') {
          i++;
          num += 400;
        } else if (i + 1 < n && s[i + 1] == 'M') {
          i++;
          num += 900;
        } else {
          num += 100;
        }
        break;
      case 'D':
        num += 500;
        break;
      case 'M':
        num += 1000;
        break;
      }
    }
    return num;
  }
};

int main(void) {
  std::string s = "MCMXCIV";
  int num = Solution{}.romanToInt(s);
  std::cout << num << '\n';
}
