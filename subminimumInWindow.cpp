#include <deque>
#include <iostream>
#include <vector>

std::vector<int> subminimumInWindow(const std::vector<int> &nums, int k) {
  std::vector<int> result;
  std::deque<int> dq1, dq2;
  for (int i = 0; i < k; i++) {
    while (!dq1.empty() && nums[dq1.back()] >= nums[i]) {
      dq1.pop_back();
    }
    dq1.push_back(i);
    for (int j = dq2.empty() ? 0 : dq2.back(); j < dq1[0]; j++) {
      while (!dq2.empty() && nums[dq2.back()] >= nums[j]) {
        dq2.pop_back();
      }
      dq2.push_back(j);
    }
  }
  if (dq2.empty()) {
    result.push_back(nums[dq1[1]]);
  } else if (dq1.size() < 2) {
    result.push_back(nums[dq2[0]]);
  } else {
    result.push_back(std::min(nums[dq1[1]], nums[dq2[0]]));
  }

  for (int i = k; i < nums.size(); i++) {
    while (!dq1.empty() && dq1.front() <= i - k) {
      dq1.pop_front();
    }
    while (!dq1.empty() && nums[dq1.back()] >= nums[i]) {
      dq1.pop_back();
    }
    dq1.push_back(i);

    while (!dq2.empty() && dq2.front() <= i - k) {
      dq2.pop_front();
    }
    for (int j = dq2.empty() ? i - k + 1 : dq2.back(); j < dq1[0]; j++) {
      while (!dq2.empty() && nums[dq2.back()] >= nums[j]) {
        dq2.pop_back();
      }
      dq2.push_back(j);
    }
    if (dq2.empty()) {
      result.push_back(nums[dq1[1]]);
    } else if (dq1.size() < 2) {
      result.push_back(nums[dq2[0]]);
    } else {
      result.push_back(std::min(nums[dq1[1]], nums[dq2[0]]));
    }
  }
  return result;
}

int main(void) {
  std::vector<int> nums = {1, 3, -1, -3, 5, -4, 6, 7};
  // result = {-1, -1, -3, -3, 5}
  // std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, -1};
  std::vector<int> result = subminimumInWindow(nums, 4);
  for (auto x : result) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  return 0;
}
