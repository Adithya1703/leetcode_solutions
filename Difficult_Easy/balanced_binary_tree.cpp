#include<algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
  public:
      int maxDepth(TreeNode* root) {
          if (root == nullptr) return 0;
          int l = maxDepth(root->left);
          int r = maxDepth(root->right);
          root->left = nullptr;
          root->right = nullptr;
          if (l == -1) return -1;
          if (r == -1) return -1;
          if (abs(l - r) > 1) return -1;
          return max(l, r) + 1;
      }
  
      bool isBalanced(TreeNode* root) {
          if (!root) return true;
          int ans = maxDepth(root);
          if (ans == -1) return false;
          return true;
      }
};