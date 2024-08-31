#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int longestSubsequence(std::vector<int> &arr, int difference) {
    std::vector<int> opt(arr.size());
    std::unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++) {
      opt[i] = 1;
      if (map.find(arr[i] - difference) != map.end()) {
        opt[i] = map[arr[i] - difference] + 1;
      }
      map[arr[i]] = std::max(map[arr[i]], opt[i]);
    }
    return *std::max_element(opt.begin(), opt.end());
  }
};

int main(void) {
  std::vector<int> arr = {1, 5, 7, 8, 5, 3, 4, 2, 1};
  int difference = -2;
  int ans = Solution{}.longestSubsequence(arr, difference);
  std::cout << ans << '\n';
  return 0;
}
