/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/

// single appraoch iterate linked list and delete duplicate

#include<iostream>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution{
public:
  ListNode* deleteDuplicates(ListNode* head){
    if(!head) return nullptr;
    ListNode* current = head;
    while(current && current->next){
      if(current->val == current->next->val){
        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
      }else{
        current = current->next;
      }
    }
    return head;
  }
};

//another approach

class Solution {
  public:
      ListNode* deleteDuplicates(ListNode* head) {
          if(head==NULL || head->next==NULL){
              return head;
          }
          ListNode* curr=head;
          ListNode* n=head;
          while(curr->next!=NULL){
              n=curr->next;
              if(curr->val!=n->val){
                  curr=n;
              }
              else{
                  curr->next=n->next;
                  n->next=NULL;
              }
          }
          return head;
      }
  };