from collections import deque
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
      self.val = val
      self.left = left
      self.right = right


class Solution:
  def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
    queue = deque([(p,q)])
    while queue:
       node1, node2 = queue.popleft()
       if not node1 and node2:
          return True
       if not node1 or node2 or node1.val!=node2.val:
          return False
       queue.append((p.left,q.left))
       queue.append((node1.right, node2.right))

    return True