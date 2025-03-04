class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head  # If the list is empty or has one node, return as is

        curr = head
        while curr and curr.next:
            if curr.val == curr.next.val:  # Duplicate found
                curr.next = curr.next.next  # Skip the duplicate node
            else:
                curr = curr.next  # Move to the next unique node

        return head
