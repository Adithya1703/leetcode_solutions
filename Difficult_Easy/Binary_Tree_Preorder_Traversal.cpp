/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include<vector>

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
      vector<int> preorderTraversal(TreeNode* root) {
          vector<int> result;
          preorderHelper(root, result);
          return result;
      }
  
  private:
      void preorderHelper(TreeNode* root, vector<int>& list) {
          if (!root) return;
          list.push_back(root->val); // Visit root
          preorderHelper(root->left, list); // Visit left subtree
          preorderHelper(root->right, list); // Visit right subtree
      }
  };


// without recursion

class Solution {
  public:
      vector<int> preorderTraversal(TreeNode* root) {
          vector<int> result;
          TreeNode* current = root;
  
          while (current) {
              if (!current->left) {
                  // Visit the node if no left child
                  result.push_back(current->val);
                  current = current->right;
              } else {
                  TreeNode* predecessor = current->left;
                  // Find the rightmost node in left subtree
                  while (predecessor->right && predecessor->right != current) {
                      predecessor = predecessor->right;
                  }
  
                  if (!predecessor->right) {
                      // Make a temporary thread and visit current
                      result.push_back(current->val);
                      predecessor->right = current;
                      current = current->left;
                  } else {
                      // Thread already exists — remove it and go right
                      predecessor->right = nullptr;
                      current = current->right;
                  }
              }
          }
  
          return result;
      }
  };
  
  