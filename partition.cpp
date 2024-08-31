#include <iostream>
#include <vector>

template <class T, class Iterator>
Iterator partition(Iterator left, Iterator right, const T &x) {
  for (Iterator it = left; it != right; it++) {
    if (*it < x) {
      std::swap(*left, *it);
      left++;
    }
  }
  return left;
}

template <class T, class Iterator>
std::pair<Iterator, Iterator> partitionThreeWay(Iterator left, Iterator right,
                                                const T &x) {
  for (Iterator it = left; it != right; it++) {
    while (it != right && *it > x) {
      right--;
      std::swap(*it, *right);
    }
    if (it == right)
      break;
    if (*it < x) {
      std::swap(*left, *it);
      left++;
    }
  }
  return {left, right};
}

std::pair<int, int> partitionThreeWay(std::vector<int> &v, int left, int right,
                                      int x) {
  for (int i = left; i < right; i++) {
    while (i < right && v[i] > x) {
      std::swap(v[i], v[--right]);
    }
    if (v[i] < x) {
      std::swap(v[left++], v[i]);
    }
  }
  return {left, right};
}

int main(void) {
  std::vector<int> vec = {4, 1, 3, 5, 6, 3};
  // auto [left, right] = partitionThreeWay(vec.begin(), vec.end(), 7);
  // std::cout << std::distance(vec.begin(), left) << ','
  //           << std::distance(vec.begin(), right) << '\n';
  auto [left, right] = partitionThreeWay(vec, 0, vec.size(), 3);
  std::cout << left << "," << right << "\n";
  for (auto x : vec) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  return 0;
}
