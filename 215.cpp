#include <functional>
#include <iostream>
#include <vector>

class Solution {
public:
  int findKthLargest(std::vector<int> &nums, int k) {
    std::vector<int> a(nums);
    k = nums.size() - k;
    int lo = 0, hi = nums.size() - 1;
    do {
      int pivot = a[hi];
      int q = lo;
      for (int j = lo; j < hi; j++) {
        if (a[j] <= pivot) {
          std::swap(a[q++], a[j]);
        }
      }
      std::swap(a[q], a[hi]);
      // a[q-x] <= a[q] < a[q+x]
      int p = lo;
      for (int j = lo; j < q; j++) {
        if (a[j] < pivot) {
          std::swap(a[p++], a[j]);
        }
      }
      // std::swap(a[q], a[p]);
      // a[p-x] < a[p] = a[q] < a[q+x]
      if (p <= k && k <= q)
        return a[p];
      else if (q < k)
        lo = q + 1;
      else
        hi = p - 1;
    } while (true);
    return 0;
  }
};

int main(void) {
  std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  int k = 4;
  int v = Solution{}.findKthLargest(nums, k);
  std::cout << v << '\n';
  return 0;
}
