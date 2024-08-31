#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int hIndex(std::vector<int> &citations) {
    std::sort(citations.begin(), citations.end(),
              [](int l, int r) { return l > r; });
    int h = 0;
    for (int i = 0; i < citations.size(); i++) {
      if (citations[i] >= i + 1) {
        h = std::max(h, i + 1);
      }
    }
    return h;
  }
};

int main(void) {
  std::vector<int> citations{1, 3, 1};
  int h = Solution{}.hIndex(citations);
  std::cout << h << '\n';
  return 0;
}
