/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
*/

struct TreeNode {
  int val;          // Node value
  TreeNode* left;   // Pointer to left child
  TreeNode* right;  // Pointer to right child
  
  // Default constructor
  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  // Constructor with value
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  // Constructor with value and left/right child pointers
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution{
  public:
    bool isMirror(TreeNode* t1, TreeNode* t2){
      if(!t1 && !t2) return true;
      if(!t1 || !t2) return false;
      return(t1->val==t2->val) && isMirror(t1->left, t2->right) && isMirror(t2->left, t1->right);
    }

    bool isSymmetric(TreeNode* root){
      if(!root) return true;
      return isMirror(root->left, root->right);
    }
};

//optimized approach

class Solution {
  public:
      bool isSymmetric(TreeNode* root) {
          if (!root) return true;
  
          bool res = isMirrored(root->left, root->right);
          root->left  = nullptr;
          root->right = nullptr;
          
          return res;
          }
  
      bool isMirrored(TreeNode* left, TreeNode* right) {
          if (!left && !right) return true;
          else if (!left || !right) return false;
          
          return (left->val == right->val) && 
              isMirrored(left->left, right->right) &&
              isMirrored(right->left, left->right);
      }
  };