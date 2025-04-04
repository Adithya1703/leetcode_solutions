/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
*/

//Brute force - keep count of visited nodes to check whether cycle or not
//Time and space comlexity both - O(n)

#include<unordered_set>
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
    bool isCycle(ListNode* head){
        unordered_set<ListNode*> visited;
        while(head){
          if(visited.count(head)){
            return true;
          }
          visited.insert(head);
          head=head->next;
        }
        return false;
    }
};

//ofcourse without unordered set also we can try brute force but it doesnt change the fact it is not optimistic

//optmistic approach - Floyd's Cycle detection algorith

class Solution{
  public:
    bool isCycle(ListNode* head){

    }
};