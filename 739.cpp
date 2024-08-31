#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
  std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
    int n = temperatures.size();
    std::vector<int> answer(n);
    std::stack<std::pair<int, int>> stk;
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && stk.top().second < temperatures[i]) {
        auto [idx, temp] = stk.top();
        stk.pop();
        answer[idx] = i - idx;
      }
      stk.push({i, temperatures[i]});
    }
    while (!stk.empty()) {
      auto [idx, temp] = stk.top();
      stk.pop();
      answer[idx] = 0;
    }
    return answer;
  }
};

int main(void) {
  std::vector<int> temperatures = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
  std::vector<int> answer = Solution{}.dailyTemperatures(temperatures);
  for (auto x : answer) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  return 0;
}
