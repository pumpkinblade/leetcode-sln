#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> triplets;
    std::vector<int> ns(nums.begin(), nums.end());
    std::sort(ns.begin(), ns.end());

    if (std::distance(std::lower_bound(ns.begin(), ns.end(), 0),
                      std::upper_bound(ns.begin(), ns.end(), 0)) >= 3) {
      triplets.push_back({0, 0, 0});
    }

    std::vector<bool> dup;
    dup.reserve(ns.size());
    dup.push_back(false);
    for (int i = 1, lead = ns.front(); i < ns.size(); i++) {
      if (ns[i] == lead) {
        dup.back() = true;
      } else {
        dup.push_back(false);
        lead = ns[i];
      }
    }
    auto last = std::unique(ns.begin(), ns.end());
    ns.erase(last, ns.end());

    // ns[m1] >= 0
    int m1 =
        std::distance(ns.begin(), std::lower_bound(ns.begin(), ns.end(), 0));
    // ns[m2] > 0
    int m2 =
        std::distance(ns.begin(), std::upper_bound(ns.begin(), ns.end(), 0));
    int n = ns.size();

    for (int p = 0; p < m1; p++) {
      for (int q = n - 1; q >= m2; q--) {
        int target = -ns[p] - ns[q];
        int i =
            std::distance(ns.begin(), std::lower_bound(ns.begin() + p + 1,
                                                       ns.begin() + q, target));
        if (i < q && ns[i] == target)
          triplets.push_back({ns[p], ns[i], ns[q]});
        else if (dup[p] && ns[p] == target)
          triplets.push_back({ns[p], ns[p], ns[q]});
        else if (dup[q] && ns[q] == target)
          triplets.push_back({ns[p], ns[q], ns[q]});
      }
    }

    return triplets;
  }
};

int main(void) {
  std::vector<int> nums = {1, 1, -2};
  std::vector<std::vector<int>> triplets = Solution{}.threeSum(nums);
  for (const std::vector<int> &triplet : triplets) {
    std::cout << triplet[0] << ',' << triplet[1] << ',' << triplet[2] << '\n';
  }
  return 0;
}
