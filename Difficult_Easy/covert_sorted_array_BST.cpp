/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
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
      TreeNode* sortedArrayToBST(vector<int>& nums) {
          TreeNode* root = new TreeNode();
          dfs(root, 0, nums.size() - 1, nums);
          return root;
      }
      void dfs(TreeNode* node, int left, int right, const vector<int>& arr)
      {
          int n = right - left + 1;
          node->val = arr[left + n/2];
          if (n == 1)
          {
              return;
          }
          node->left = new TreeNode();
          dfs(node->left, left, left + n/2 -1, arr);
          if (n > 2)
          {
              node->right = new TreeNode();
              dfs(node->right, left + n/2 + 1, right, arr);
          }
          return;
      }
  };