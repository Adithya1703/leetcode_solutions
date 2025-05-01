/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Time Complexity:
 * The function `removeElements` is called recursively for each node in the linked list.
 * In the worst case, the function will traverse all `n` nodes in the list once.
 * Therefore, the time complexity is O(n), where `n` is the number of nodes in the linked list.
 *
 * Space Complexity:
 * The function uses recursion, which adds a function call to the call stack for each node in the list.
 * In the worst case, the recursion depth will be equal to the number of nodes in the list, `n`.
 * Therefore, the space complexity due to the call stack is O(n).
 */
class Solution{
  public:
    ListNode* removeElements(ListNode* head, int val){
      if(head == nullptr){
        return head;
      }
      head->next = removeElements(head->next, val);
      if(head->val == val){
        ListNode* temp = head;
        delete head;
        return temp;
      }
      return head;
    }

    // another approach
    ListNode* removeElements(ListNode* head, int val){
      ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* current = dummy;  // Start from the dummy node
        
        // Traverse the list
        while (current->next != nullptr) {
            if (current->next->val == val) {
                current->next = current->next->next;  // Remove the node
            } else {
                current = current->next;  // Move to the next node
            }
        }
        
        // The head of the modified list is now dummy->next
        ListNode* newHead = dummy->next;
        delete dummy;  // Free the dummy node to prevent memory leak
        return newHead;
    }

    //


};