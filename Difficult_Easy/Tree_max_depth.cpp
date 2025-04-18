/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/

#include<algorithm>
using namespace std;

struct TreeNode {
  int val;              // Value of the node
  TreeNode *left;       // Pointer to the left child
  TreeNode *right;      // Pointer to the right child

  // Default constructor (initializes value to 0, and left and right children to nullptr)
  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  // Constructor with value
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  // Constructor with value and left/right children
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution{
  public:
    int maxDepth(TreeNode* root){
      if(!root) return 0;
      int left = maxDepth(root->left);
      int right = maxDepth(root->right);
      return 1+max(left, right);
    }
};


//Optimized:

class Solution {
  public:
      int maxDepth(TreeNode* root) {
          if(!root) return 0;
          int ans = 1+max(maxDepth(root->left), maxDepth(root->right));
          root->left = nullptr;
          root->right = nullptr;
          return ans;
      }
  };