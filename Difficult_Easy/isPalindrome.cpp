/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
*/


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  bool isPalindrome(ListNode* head){
    if(!head || !head->next) return true;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode* prev = nullptr;
    while(slow){
      ListNode* temp = slow->next;
      slow->next = prev;
      prev = slow;
      slow = temp;
    }
    ListNode* left = head;
    ListNode* right = prev;
    while(right){
      if(left->val != right->val) return false;
      left = left->next;
      right = right->next;
    }
    return true;
  }  
};