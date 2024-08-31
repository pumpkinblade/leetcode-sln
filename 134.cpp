#include <iostream>
#include <vector>

class Solution {
public:
  int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
    int n = gas.size();
    std::vector<int> res(n);
    for (int i = 0; i < n; i++) {
      res[i] = gas[i] - cost[i];
    }

    int acc = 0;
    int len = 0;
    int start = -1;
    while (start < n && len < n) {
      start += len + 1;
      len = 0;
      acc = 0;
      do {
        acc += res[(start + len) % n];
      } while (acc >= 0 && ++len < n);
    }
    return len == n ? start : -1;
  }
};

int main(void) {
  std::vector<int> gas{1, 2, 3, 4, 5};
  std::vector<int> cost{3, 4, 5, 1, 2};
  int start = Solution{}.canCompleteCircuit(gas, cost);
  std::cout << "start = " << start << '\n';
}
