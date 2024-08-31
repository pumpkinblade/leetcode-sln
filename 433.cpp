#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

class Solution {
public:
  int minMutation(std::string startGene, std::string endGene,
                  std::vector<std::string> &bank) {
    std::queue<std::pair<std::string, int>> queue;
    queue.push({startGene, 0});
    std::vector<bool> mark(bank.size(), false);
    auto it = std::find(bank.begin(), bank.end(), startGene);
    if (it != bank.end()) {
      mark[std::distance(bank.begin(), it)] = true;
    }
    while (!queue.empty()) {
      auto [s, c] = queue.front();
      queue.pop();

      if (s == endGene)
        return c;
      for (int i = 0; i < bank.size(); i++) {
        if (mark[i])
          continue;
        int d = 0;
        for (int j = 0; j < s.size(); j++) {
          if (s[j] != bank[i][j])
            d++;
        }
        if (d == 1) {
          queue.push({bank[i], c + 1});
          mark[i] = true;
        }
      }
    }
    return -1;
  }
};

int main(void) {
  std::string startGene = "AAAAACCC";
  std::string endGene = "AACCCCCC";
  std::vector<std::string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
  int res = Solution{}.minMutation(startGene, endGene, bank);
  std::cout << res << "\n";
}
