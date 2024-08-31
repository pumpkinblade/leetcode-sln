#include <iostream>
#include <vector>
class Solution {
public:
  int candy(std::vector<int> &ratings) {
    int n = ratings.size();
    int node = 0;
    int left = 0, right = 0;
    int result = 0;
    while (right < n - 1) {
      left = right;
      if (ratings[right] < ratings[right + 1]) { // ascend
        // std::cout << "ascend\n";
        do {
          right++;
        } while (right < n - 1 && ratings[right] < ratings[right + 1]);
        result += (right - left) * (right - left + 1) / 2;
        node = right - left;
      } else if (ratings[right] > ratings[right + 1]) { // descend
        // std::cout << "descend\n";
        do {
          right++;
        } while (right < n - 1 && ratings[right] > ratings[right + 1]);
        result += (right - left - 1) * (right - left) / 2;
        result += std::max((right - left) - node, 0);
        node = 0;
      } else { // flat
        // std::cout << "flat\n";
        do {
          right++;
        } while (right < n - 1 && ratings[right] == ratings[right + 1]);
        node = 0;
      }
    }
    return result + n;
  }
};

int main(void) {
  std::vector<int> ratings{5, 3, 7, 3};
  int res = Solution{}.candy(ratings);
  std::cout << res << '\n';
  return 0;
}
