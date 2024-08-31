#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums) {
    std::vector<int> prefix(nums.size());
    std::vector<int> postfix(nums.size());
    prefix[0] = postfix[nums.size() - 1] = 1;
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      prefix[i] = prefix[i - 1] * nums[i - 1];
      postfix[n - i - 1] = postfix[n - i] * nums[n - i];
    }
    std::vector<int> ans(nums.size());
    for (int i = 0; i < n; i++) {
      ans[i] = prefix[i] * postfix[i];
    }
    return ans;
  }

  std::vector<int> productExceptSelf2(std::vector<int> &nums) {
    std::vector<int> ans(nums.size());
    ans[0] = 1;
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      ans[i] = ans[i - 1] * nums[i - 1];
    }
    int cum = 1;
    for (int i = n - 1; i >= 0; --i) {
      ans[i] = cum * ans[i];
      cum *= nums[i];
    }
    return ans;
  }
};
