#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> fullJustify(std::vector<std::string> &words,
                                       int maxWidth) {
    std::vector<std::string> res;
    for (int i = 0; i < words.size();) {
      int w1 = words[i].size();
      int j = i + 1;
      while (j < words.size()) {
        if (w1 + 1 + words[j].size() > maxWidth)
          break;
        w1 += 1 + words[j].size();
        j++;
      }
      std::ostringstream oss;

      if (j - i == 1 || j == words.size()) { // left
        oss << words[i++];
        while (i < j) {
          oss << ' ' << words[i++];
        }
        while (maxWidth - w1 > 0) {
          oss << ' ';
          w1++;
        }
      } else { // middle
        w1 -= (j - i - 1);
        int ns = (maxWidth - w1) / (j - i - 1);
        // (1 + ns) * x0 + ns * (j - i - 1 - x0) = maxWidth - w1
        // => x0 = maxWidth - w1 - ns * (j - i - 1)
        int x0 = maxWidth - w1 - ns * (j - i - 1);
        oss << words[i++];
        while (i < j) {
          for (int s = 0; s < ns; s++)
            oss << ' ';
          if (x0 > 0)
            oss << ' ';
          x0--;

          oss << words[i++];
        }
      }
      res.push_back(oss.str());
    }
    return res;
  }
};

int main(void) {
  std::vector<std::string> words = {
      "This", "is", "an", "example", "of", "text", "justification."};
  int maxWidth = 16;
  std::vector<std::string> result = Solution{}.fullJustify(words, maxWidth);
  for (int i = 0; i < result.size(); i++) {
    std::cout << std::quoted(result[i]) << '\n';
  }
  return 0;
}
