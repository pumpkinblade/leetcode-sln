#include <iostream>
#include <vector>

class Solution {
public:
  void rotate(std::vector<int> &nums, int k) {
    if (nums.size() == 0)
      return;
    k %= nums.size();
    if (k == 0)
      return;
    int n1 = nums.size(), n2 = k, n3 = n1 % n2;
    while (n3) {
      n1 = n2;
      n2 = n3;
      n3 = n1 % n2;
    }
    n1 = nums.size() / n2;
    for (int i = 0; i < n2; i++) {
      int c = nums[i];
      n3 = i;
      for (int j = 0; j < n1; j++) {
        n3 = (n3 + k) % nums.size();
        std::swap(nums[n3], c);
      }
    }
  }

  void reverse(std::vector<int> &nums, int i, int j) {
    while (i < j) {
      std::swap(nums[i], nums[j]);
      i--;
      j--;
    }
  }

  void rotateByReverse(std::vector<int> &nums, int k) {
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k % nums.size() - 1);
    reverse(nums, k % nums.size(), nums.size() - 1);
  }
};

int main(void) {
  std::vector<int> nums{1, -1, -100, 3, 9};
  int k = 2;
  Solution{}.rotate(nums, k);
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << ' ';
  }
  std::cout << '\n';
}
