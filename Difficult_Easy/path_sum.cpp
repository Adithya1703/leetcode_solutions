struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
  public:
    bool pathSum(TreeNode* root, int TargetSum){
      if(!root) return false;
      if(!root->left && !root->right && root->val==TargetSum){
        return true;
      }
      return pathSum(root->left, TargetSum-root->val) || pathSum(root->right, TargetSum-root->val);
    }
};