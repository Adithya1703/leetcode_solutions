class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        res = self.isMirrored(root.left, root.right)
        root.left = None
        root.right = None
        return res

    def isMirrored(self, left: TreeNode, right: TreeNode) -> bool:
        if not left and not right:
            return True
        if not left or not right:
            return False
        
        return (left.val == right.val and 
                self.isMirrored(left.left, right.right) and 
                self.isMirrored(left.right, right.left))
