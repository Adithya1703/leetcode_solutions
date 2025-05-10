/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.
*/

#include <iostream>

using namespace std;

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

    // Using recursion to count the number of nodes in a binary tree
    // Time complexity: O(n), where n is the number of nodes in the tree
    // Space complexity: O(h), where h is the height of the tree (due to recursion stack)
    // This is not the optimal solution as it traverses all nodes in the tree
    int countNodes(TreeNode* root){
        if(!root) return 0;

        return 1+countNodes(root->left)+countNodes(root->right);
    }

    /*Optimal Solution*/
    // Using binary search to count the number of nodes in a complete binary tree
    // Time complexity: O(log^2 n), where n is the number of nodes in the tree
    // Space complexity: O(1), as we are not using any extra space
    int countNodesOptimal(TreeNode* root){
        if(!root) return 0;
        int leftHeight = 0, rightHeight = 0;
        TreeNode* left = root;
        TreeNode* right = root;
        while(left){
            leftHeight++;
            left = left->left;
        }
        while(right){
            rightHeight++;
            right = right->right;
        }
        if(leftHeight == rightHeight){
            return(1<<leftHeight)-1; // 2^h - 1
        }
        return 1 + countNodesOptimal(root->left) + countNodesOptimal(root->right);
    }

};