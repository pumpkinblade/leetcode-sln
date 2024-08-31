#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int> res;
    int n = s.size(), m = p.size();
    if (n < m)
      return res;

    std::vector<int> cs(26, 0), cp(26, 0);
    for (int i = 0; i < m; i++) {
      cp[p[i] - 'a']++;
    }
    for (int j = 0; j < m; j++) {
      cs[s[j] - 'a']++;
    }
    int k = 0;
    for (k = 0; k < 26; k++) {
      if (cs[k] != cp[k]) {
        break;
      }
    }
    if (k == 26) {
      res.push_back(0);
    }
    for (int j = m; j < n; j++) {
      // check s[j-m+1...j]
      cs[s[j] - 'a']++;
      cs[s[j - m] - 'a']--;
      for (k = 0; k < 26; k++) {
        if (cs[k] != cp[k]) {
          break;
        }
      }
      if (k == 26) {
        res.push_back(j - m + 1);
      }
    }
    return res;
  }
};

int main(void) {
  std::string s = "ab";
  std::string p = "abab";
  auto res = Solution{}.findAnagrams(s, p);
  for (auto x : res) {
    std::cout << x << '\n';
  }
  return 0;
}
