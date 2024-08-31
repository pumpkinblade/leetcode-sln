struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int countLeft(TreeNode *root) {
    int h = 0;
    while (root) {
      h++;
      root = root->left;
    }
    return h;
  }

  int countRight(TreeNode *root) {
    int h = 0;
    while (root) {
      h++;
      root = root->right;
    }
    return h;
  }
  int countNodes(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int ll = countLeft(root->left);
    int rr = countRight(root->right);
    int count = 0;

    while (ll != rr) {
      int lr = countRight(root->left);
      int rl = countLeft(root->right);
      if (ll == lr && rl == rr) {
        count += (1 << ll) - 1;
        count += (1 << rr) - 1;
        count++;
        return count;
      } else if (ll == lr) {
        count += (1 << ll);
        ll = rl - 1;
        rr = rr - 1;
        root = root->right;
      } else if (rl == rr) {
        count += (1 << rr);
        rr = lr - 1;
        ll = ll - 1;
        root = root->left;
      }
    }
    count += (1 << (ll + 1)) - 1;
    return count;
  }
};
