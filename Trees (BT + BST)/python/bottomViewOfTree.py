# Problem Statement: Given a binary tree, print the bottom view from left to right. A node is included in the bottom view if it can be seen when we look at the tree from the bottom.

# Problem Link: https://www.codingninjas.com/studio/problems/bottom-view-of-binary-tree_893110?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def bottom_view(root):
    ans = []
    if not root:
        return ans
        
    q = deque([(0, root)])
    m = {}
    
    while q:
        hd, node = q.popleft()
        
        m[hd] = node.val
        
        if node.left:
            q.append((hd - 1, node.left))
            
        if node.right:
            q.append((hd + 1, node.right))
            
    for hd in sorted(m.keys()):
        ans.append(m[hd])
        
    return ans
