#include <array>
#include <iostream>
#include <vector>

class Solution {
public:
  long long sumDigitDifferences(std::vector<int> &nums) {
    std::vector<std::array<int, 10>> lut;

    for (int x = nums[0]; x; x /= 10) {
      lut.emplace_back();
      lut.back()[x % 10]++;
    }

    long long result = 0;
    for (int i = 1; i < nums.size(); i++) {
      for (int x = nums[i], j = 0; x; x /= 10, j++) {
        result += i - lut[j][x % 10];
        lut[j][x % 10]++;
      }
    }

    return result;
  }
};

int main(void) {
  // std::vector<int> nums = {13, 23, 12};
  std::vector<int> nums = {10, 10, 10, 10};
  auto result = Solution{}.sumDigitDifferences(nums);
  std::cout << result << '\n';
  return 0;
}
