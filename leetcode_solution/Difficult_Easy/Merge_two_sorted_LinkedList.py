class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        if not list1:
            return list2
        if not list2:
            return list1

        # Ensure list1 always points to the smaller head
        if list1.val > list2.val:
            list1, list2 = list2, list1

        result = list1  # The final merged linked list

        while list1 and list2:
            temp = None
            while list1 and list1.val <= list2.val:
                temp = list1  # Keep track of last sorted node
                list1 = list1.next

            # Link temp.next to list2, making list2 the new continuation
            temp.next = list2

            # Swap list1 and list2 to always continue with the smaller value
            list1, list2 = list2, list1

        return result
