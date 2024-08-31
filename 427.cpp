#include <vector>

// Definition for a QuadTree node.
class Node {
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
       Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
public:
  Node *impl(std::vector<std::vector<int>> &acc, int x1, int x2, int y1,
             int y2) {
    // handle [x1, x2) x [y1, y2)
    int area = (x2 - x1) * (y2 - y1);
    int count = acc[y2 - 1][x2 - 1];
    count -= (x1 - 1 >= 0 ? acc[y2 - 1][x1 - 1] : 0);
    count -= (y1 - 1 >= 0 ? acc[y1 - 1][x2 - 1] : 0);
    count += (y1 - 1 >= 0 && x1 - 1 >= 0 ? acc[y1 - 1][x1 - 1] : 0);

    // std::printf("[%d, %d) x [%d, %d) area = %d count = %d\n", x1, x2, y1, y2,
    //             area, count);
    if (count == 0) {
      return new Node(0, true);
    } else if (count == area) {
      return new Node(1, true);
    } else {
      int x3 = (x1 + x2) / 2;
      int y3 = (y1 + y2) / 2;
      Node *tl = impl(acc, x1, x3, y1, y3);
      Node *tr = impl(acc, x3, x2, y1, y3);
      Node *bl = impl(acc, x1, x3, y3, y2);
      Node *br = impl(acc, x3, x2, y3, y2);
      return new Node(0, false, tl, tr, bl, br);
    }
  }
  Node *construct(std::vector<std::vector<int>> &grid) {
    int n = grid.size();
    std::vector<std::vector<int>> acc(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      acc[i][0] = grid[i][0];
      for (int j = 1; j < n; j++) {
        acc[i][j] = acc[i][j - 1] + grid[i][j];
      }
    }
    for (int j = 0; j < n; j++) {
      for (int i = 1; i < n; i++) {
        acc[i][j] = acc[i - 1][j] + acc[i][j];
      }
    }
    return impl(acc, 0, n, 0, n);
  }
};

int main(void) {
  std::vector<std::vector<int>> grid = {
      {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
      {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}};
  Solution{}.construct(grid);
}
