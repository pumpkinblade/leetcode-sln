#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    std::vector<int> res;

    std::vector<std::pair<int, int>> q(nums.size()); // <index, val>
    int head = 0, tail = 0;
    for (int i = 0; i < k; i++) {
      while (head < tail && q[tail - 1].second <= nums[i]) {
        tail--;
      }
      q[tail++] = {i, nums[i]};
    }
    res.push_back(q[head].second);

    for (int i = k; i < nums.size(); i++) {
      // [i-k+1,...,i]
      while (head < tail && q[head].first <= i - k) {
        head++;
      }
      while (head < tail && q[tail - 1].second <= nums[i]) {
        tail--;
      }
      q[tail++] = {i, nums[i]};
      res.push_back(q[head].second);
    }

    return res;
  }
};

int main(void) {
  std::vector<int> nums = {1};
  int k = 1;
  auto res = Solution{}.maxSlidingWindow(nums, k);
  for (auto x : res) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  return 0;
}
