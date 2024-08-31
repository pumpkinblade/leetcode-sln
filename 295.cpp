#include <iostream>
#include <queue>
#include <vector>

class MedianFinder {
public:
  MedianFinder() : n(0) {}

  void addNum(int num) {
    if (n == 0) {
      leftQueue.push(num);
      rightQueue.push(num);
    } else if (n % 2) {
      int val = leftQueue.top();
      if (num < val) {
        leftQueue.pop();
        leftQueue.push(num);
      } else {
        rightQueue.pop();
        rightQueue.push(num);
      }
    } else {
      if (num < leftQueue.top()) {
        rightQueue.push(leftQueue.top());
        leftQueue.push(num);
      } else if (num < rightQueue.top()) {
        rightQueue.push(num);
        leftQueue.push(num);
      } else {
        leftQueue.push(rightQueue.top());
        rightQueue.push(num);
      }
    }
    n++;
  }

  double findMedian() { return (leftQueue.top() + rightQueue.top()) / 2.0; }

private:
  int n;
  std::priority_queue<int, std::vector<int>, std::less<int>> leftQueue;
  std::priority_queue<int, std::vector<int>, std::greater<int>> rightQueue;
};

int main(void) {}
