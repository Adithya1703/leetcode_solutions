/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

//Brute force approach - compare between LL head in each iteration and add to tail
//time complexity - O(N+M) two list
//space complexity - O(N) - using extra space
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if (list1 == NULL) return list2;
      if (list2 == NULL) return list1;

      ListNode *Head = NULL;
      ListNode *tail = NULL;

      if (list1->val < list2->val) {
          Head = new ListNode(list1->val);
          tail = Head;
          list1 = list1->next;
      } else {
          Head = new ListNode(list2->val);
          tail = Head;
          list2 = list2->next;
      }

      while (list1 != NULL && list2 != NULL) {
          if (list1->val < list2->val) {
              tail->next = new ListNode(list1->val);
              list1 = list1->next;
          } else {
              tail->next = new ListNode(list2->val);
              list2 = list2->next;
          }
          tail = tail->next;
      }

      // Append remaining nodes (if any)
      while (list1 != NULL) {
          tail->next = new ListNode(list1->val);
          list1 = list1->next;
          tail = tail->next;
      }

      while (list2 != NULL) {
          tail->next = new ListNode(list2->val);
          list2 = list2->next;
          tail = tail->next;
      }

      return Head;
  }
};


//Optimized Solution

class Solution {
  public:
      ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
          if (!list1) return list2;
          if (!list2) return list1;
  
          // Ensure list1 always points to the smaller head
          if (list1->val > list2->val) swap(list1, list2);
  
          ListNode* result = list1; // Final merged list starts from list1
  
          while (list1 && list2) {
              ListNode* temp = nullptr;
              // Move list1 forward while it's smaller
              while (list1 && list1->val <= list2->val) {
                  temp = list1;  // Keep track of last sorted node
                  list1 = list1->next;
              }
              // Link temp->next to list2, making list2 the new continuation
              temp->next = list2;
              // Swap list1 and list2, so that list1 always points to the smaller value
              swap(list1, list2);
          }
  
          return result; 
      }
  };
  
