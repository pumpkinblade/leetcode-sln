#include <algorithm>
#include <queue>
#include <string>
#include <vector>

class Solution {
public:
  int ladderLength(std::string beginWord, std::string endWord,
                   std::vector<std::string> &wordList) {
    std::queue<std::pair<std::string, int>> queue;
    queue.push({beginWord, 1});
    std::vector<bool> mark(wordList.size(), false);
    auto it = std::find(wordList.begin(), wordList.end(), beginWord);
    if (it != wordList.end()) {
      mark[std::distance(wordList.begin(), it)] = true;
    }
    while (!queue.empty()) {
      auto [s, c] = queue.front();
      queue.pop();

      if (s == endWord)
        return c;
      for (int i = 0; i < wordList.size(); i++) {
        if (mark[i])
          continue;
        int d = 0;
        for (int j = 0; j < s.size(); j++) {
          if (s[j] != wordList[i][j])
            d++;
        }
        if (d == 1) {
          queue.push({wordList[i], c + 1});
          mark[i] = true;
        }
      }
    }
    return 0;
  }
};
