#include <cctype>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  std::string decodeString(std::string s) {
    std::stack<int> numStk;
    std::stack<std::string> strStk;
    strStk.push("");
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
      if (std::isdigit(s[i])) {
        num = num * 10 + s[i] - '0';
      } else if (s[i] == '[') {
        numStk.push(num);
        num = 0;
        strStk.push("");
      } else if (s[i] == ']') {
        std::string word = strStk.top();
        strStk.pop();
        int ie = numStk.top();
        numStk.pop();
        for (int i = 0; i < ie; i++) {
          strStk.top() += word;
        }
      } else {
        strStk.top() += s[i];
      }
    }
    return strStk.top();
  }
};

int main(void) {
  std::string s = "2[abc]3[cd]ef";
  std::string result = Solution{}.decodeString(s);
  std::cout << result << '\n';
  return 0;
}
