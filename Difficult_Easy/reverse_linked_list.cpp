/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// iterative approach

class Solution{
public:
  // iterative approach
  ListNode* reverse_LL(ListNode* head){
    ListNode* current = head;
    ListNode* prev = nullptr;
    while(current){
        ListNode* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    return prev;
  }
  
  // recursive approach
  ListNode* reverse_List(ListNode* head){
      if(!head ||!head->next) return head;
      ListNode* new_head = reverse_List(head->next);
      head->next->next = head;
      head->next = nullptr;
      return new_head;
  }
};

