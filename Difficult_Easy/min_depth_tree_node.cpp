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
      int minDepth(TreeNode* root) {
          if (root == nullptr) return 0;
          
          // If it's a leaf node, return depth as 1
          if (root->left == nullptr && root->right == nullptr) {
              return 1;
          }
  
          // If one of the children is nullptr, take the depth of the non-null subtree
          if (root->left == nullptr) {
              return 1 + minDepth(root->right);
          }
          if (root->right == nullptr) {
              return 1 + minDepth(root->left);
          }
  
          // If both children exist, take the minimum of both depths
          return 1 + std::min(minDepth(root->left), minDepth(root->right));
      }
  };