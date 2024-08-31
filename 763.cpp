#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> partitionLabels(std::string s) {
    std::vector<int> res;
    std::unordered_map<char, int> map;
    for (int i = 0; i < s.size(); i++) {
      map[s[i]] = i;
    }
    for (int i = 0; i < s.size();) {
      int start = i;
      int end = map[s[i]];
      for (i += 1; i <= end; i++) {
        end = std::max(end, map[s[i]]);
      }
      res.push_back(end - start + 1);
    }
    return res;
  }
};

int main(void) {
  std::string s = "ababcbacadefegdehijhklij";
  std::vector<int> lengths = Solution{}.partitionLabels(s);
  for (auto l : lengths) {
    std::cout << l << '\n';
  }
  return 0;
}
