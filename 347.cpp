#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> freq;
    for (auto x : nums) {
      freq[x]++;
    }
    std::vector<std::pair<int, int>> vfs;
    for (auto vf : freq) {
      vfs.push_back(vf);
    }

    // find the k-max
    std::vector<int> res;
    int start = 0, end = vfs.size();
    while (start < end) {
      int left = start, right = end;
      int pivot = vfs[left].second;
      for (int i = left; i < right; i++) {
        while (i < right && vfs[i].second < pivot) {
          std::swap(vfs[i], vfs[--right]);
        }
        if (vfs[i].second > pivot) {
          std::swap(vfs[i], vfs[left++]);
        }
      }
      if (left <= k && k < right) {
        for (int i = start; i < k; i++) {
          res.push_back(vfs[i].first);
        }
        break;
      } else if (k < left) {
        end = left;
      } else {
        for (int i = start; i < right; i++) {
          res.push_back(vfs[i].first);
        }
        start = right;
      }
    }
    return res;
  }
};

int main(void) {
  std::vector<int> nums = {5,  -3, 9, 1,  7, 7, 9,  10, 2, 2,
                           10, 10, 3, -1, 3, 7, -9, -1, 3, 3};
  int k = 3;
  auto res = Solution{}.topKFrequent(nums, k);
  for (auto x : res) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  return 0;
}
