#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &numbers, int target) {
    int p = 0, q = numbers.size() - 1;
    while (p < q) {
      while (p < q && numbers[p] + numbers[q] < target) {
        p++;
      }
      if (p < q && numbers[p] + numbers[q] == target) {
        return std::vector<int>{p + 1, q + 1};
      } else {
        q--;
      }
    }
    return std::vector<int>{0, 0};
  }
};

int main(void) {
  std::vector<int> numbers = {-1, 0};
  int target = -1;
  std::vector<int> pair = Solution{}.twoSum(numbers, target);
  std::cout << pair.front() << ',' << pair.back() << '\n';
  return 0;
}
