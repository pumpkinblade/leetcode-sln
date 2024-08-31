#include <iostream>
#include <vector>

class Solution {
public:
  int maxUncrossedLines(std::vector<int> &nums1, std::vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    std::vector<std::vector<int>> opt(1 + m, std::vector<int>(1 + n));
    for (int j = 0; j <= n; j++)
      opt[0][j] = 0;
    for (int i = 1; i <= m; i++) {
      opt[i][0] = 0;
      for (int j = 1; j <= n; j++) {
        opt[i][j] = nums1[i - 1] == nums2[j - 1]
                        ? 1 + opt[i - 1][j - 1]
                        : std::max(opt[i - 1][j], opt[i][j - 1]);
      }
    }
    return opt[m][n];
  }
};

int main(void) {
  std::vector<int> nums1 = {1, 4, 2};
  std::vector<int> nums2 = {1, 2, 4};
  int ans = Solution{}.maxUncrossedLines(nums1, nums2);
  std::cout << ans << '\n';
  return 0;
}
