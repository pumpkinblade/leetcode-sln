#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> kSmallestPairs(std::vector<int> &nums1,
                                               std::vector<int> &nums2, int k) {
    struct IJV {
      int i, j, val;
      bool operator<(const IJV &other) const { return val > other.val; }
    };
    std::priority_queue<IJV> queue;
    std::vector<std::vector<int>> result;
    for (int i = 0; i < nums1.size(); i++) {
      queue.push({i, 0, nums1[i] + nums2[0]});
    }
    while (k--) {
      auto [i, j, v] = queue.top();
      queue.pop();

      result.push_back({nums1[i], nums2[j]});
      if (j + 1 < nums2.size()) {
        queue.push({i, j + 1, nums1[i] + nums2[j + 1]});
      }
    }
    return result;
  }
};

int main(void) {
  std::vector<int> nums1 = {1, 7, 11};
  std::vector<int> nums2 = {2, 4, 6};
  int k = 3;
  auto result = Solution{}.kSmallestPairs(nums1, nums2, k);
  for (auto &pair : result) {
    std::cout << pair.front() << ' ' << pair.back() << '\n';
  }
  return 0;
}
