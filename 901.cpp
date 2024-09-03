#include <vector>

class StockSpanner {
public:
  int day;
  std::vector<std::pair<int, int>> stk;
  StockSpanner() : day(0) {}

  int next(int price) {
    day++;
    int ans = 0;
    while (!stk.empty() && stk.back().second <= price) {
      stk.pop_back();
    }
    if (stk.empty()) {
      ans = day;
    } else {
      ans = day - stk.back().first;
    }
    stk.emplace_back(day, price);
    return ans;
  }
};
