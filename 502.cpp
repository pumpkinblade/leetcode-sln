#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
  int findMaximizedCapital(int k, int w, std::vector<int> &profits,
                           std::vector<int> &capital) {
    int n = profits.size();
    std::priority_queue<int, std::vector<int>, std::less<int>> pq;
    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < n; i++) {
      pairs.emplace_back(capital[i], profits[i]);
    }
    auto comp = [](std::pair<int, int> x, std::pair<int, int> y) {
      return x.first < y.first;
    };
    std::sort(pairs.begin(), pairs.end(), comp);
    for (int i = 0, j = 0; i < k; i++) {
      for (; j < pairs.size() && pairs[j].first <= w; j++) {
        pq.push(pairs[j].second);
      }
      if (pq.empty())
        break;
      w += pq.top();
      pq.pop();
    }
    return w;
  }
};

int main(void) {
  int k = 2;
  int w = 0;
  std::vector<int> profits = {1, 2, 3};
  std::vector<int> capital = {0, 1, 1};
  int result = Solution{}.findMaximizedCapital(k, w, profits, capital);
  std::cout << result << '\n';
}
