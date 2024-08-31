#include <string>

class Solution {
public:
  int lengthOfLastWord(std::string s) {
    int n = s.size();
    int n1 = n - 1;
    while (n1 >= 0 && s[n1] == ' ')
      --n1;
    int n2 = n1;
    while (n2 >= 0 && s[n2] != ' ')
      --n2;
    return n1 - n2;
  }
};
