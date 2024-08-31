#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int maximalSquare(std::vector<std::vector<char>> &matrix) {
    int m = matrix.size();
    int n = matrix.front().size();
    int maxlen = 0;
    std::vector<int> hori(n), vert(n), len(n), prevLen(n);

    len[0] = vert[0] = hori[0] = matrix[0][0] == '1';
    maxlen = std::max(maxlen, len[0]);
    for (int j = 1; j < n; j++) {
      hori[j] = matrix[0][j] == '1' ? 1 + hori[j - 1] : 0;
      vert[j] = matrix[0][j] == '1';
      len[j] = matrix[0][j] == '1';
      maxlen = std::max(maxlen, len[j]);
    }
    len.swap(prevLen);
    for (int i = 1; i < m; i++) {
      hori[0] = matrix[i][0] == '1';
      vert[0] = matrix[i][0] == '1' ? 1 + vert[0] : 0;
      len[0] = matrix[i][0] == '1';
      maxlen = std::max(maxlen, len[0]);
      for (int j = 1; j < n; j++) {
        hori[j] = matrix[i][j] == '1' ? 1 + hori[j - 1] : 0;
        vert[j] = matrix[i][j] == '1' ? 1 + vert[j] : 0;
        len[j] = matrix[i][j] == '1'
                     ? std::min({prevLen[j - 1] + 1, vert[j], hori[j]})
                     : 0;
        maxlen = std::max(maxlen, len[j]);
      }
      len.swap(prevLen);
    }
    return maxlen * maxlen;
  }
};

int main(void) {
  std::vector<std::vector<char>> matrix = {
      {'1', '0', '1', '0'},
      {'1', '0', '1', '1'},
      {'1', '0', '1', '1'},
      {'1', '1', '1', '1'},
  };
  int area = Solution{}.maximalSquare(matrix);
  std::cout << area << '\n';
  return 0;
}
