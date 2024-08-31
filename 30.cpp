#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> findSubstring(std::string s,
                                 std::vector<std::string> &words) {
    int n = s.size();
    int wc = words.size();
    int wl = words.front().size();
    std::vector<int> indices;
    std::vector<int> target;
    std::unordered_map<std::string, int> map;
    for (const auto &word : words) {
      if (map.find(word) == map.end()) {
        map.emplace(word, target.size());
        target.push_back(1);
      } else {
        target[map[word]]++;
      }
    }

    std::vector<int> nums;
    nums.reserve(n / wl);
    for (int i = 0; i < wl; i++) {
      nums.clear();
      for (int j = i; j < n; j += wl) {
        nums.push_back(-1);
        for (int k = 0; k < wc; k++) {
          if (s.substr(j, wl) == words[k]) {
            nums.back() = map[words[k]];
          }
        }
      }
      std::vector<int> inds = findSubstringImpl(nums, target);
      for (auto idx : inds) {
        indices.push_back(i + wl * idx);
      }
    }
    return indices;
  }

  std::vector<int> findSubstringImpl(const std::vector<int> &nums,
                                     const std::vector<int> &target) {
    std::vector<int> indices;
    int m = target.size();
    int n = nums.size();
    int l = std::accumulate(target.begin(), target.end(), 0, std::plus<int>{});
    std::vector<int> curr(m, 0);
    auto check = [&]() {
      for (int i = 0; i < m; i++) {
        if (curr[i] != target[i])
          return false;
      }
      return true;
    };

    if (n < l)
      return indices;

    int p = 0, q = 0;
    for (; q < l; q++) {
      if (nums[q] >= 0)
        curr[nums[q]]++;
    }
    if (check()) {
      indices.push_back(p);
    }
    for (; q < n; q++, p++) {
      if (nums[p] >= 0)
        curr[nums[p]]--;
      if (nums[q] >= 0)
        curr[nums[q]]++;
      if (check()) {
        indices.push_back(p + 1);
      }
    }
    return indices;
  }
};

int main(void) {
  std::string s = "aaaaaaaaaaaaaa";
  std::vector<std::string> words = {"a", "a"};
  auto indices = Solution{}.findSubstring(s, words);
  for (auto idx : indices) {
    std::cout << idx << ' ';
  }
  std::cout << '\n';
}
