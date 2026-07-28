# Problem Statement: You are given a binary tree with distinct node values and a starting node 'start'. The tree is on fire, and it takes 1 unit of time for the fire to spread from a node to any of its neighboring nodes (parent, left child, or right child).
# Your task is to calculate the minimum time required for the entire tree to be engulfed in flames, starting from the node with value 'start'. Write a function 'timeToBurnTree' that takes the root of the binary tree and the starting node value 'start' as input and returns the minimum time needed for the entire tree to burn.

# Problem Link: https://www.codingninjas.com/studio/problems/time-to-burn-tree_1469067?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

from collections import deque

class BinaryTreeNode:
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None

def find_parent(target, par):
    if not target:
        return
        
    if target.left:
        par[target.left] = target
    if target.right:
        par[target.right] = target
        
    find_parent(target.left, par)
    find_parent(target.right, par)

def find_start(target, start):
    if not target:
        return None
        
    if target.data == start:
        return target
        
    left_result = find_start(target.left, start)
    if left_result is None:
        return find_start(target.right, start)
    return left_result

def time_to_burn_tree(root, start):
    par = {}
    find_parent(root, par)
    
    vis = {}
    target = find_start(root, start)
    
    if target is None:
        return 0
        
    q = deque([target])
    vis[target] = True
    ans = 0
    
    while q:
        sz = len(q)
        for _ in range(sz):
            temp = q.popleft()
            
            if temp in par and par[temp] not in vis:
                vis[par[temp]] = True
                q.append(par[temp])
            if temp.left and temp.left not in vis:
                vis[temp.left] = True
                q.append(temp.left)
            if temp.right and temp.right not in vis:
                vis[temp.right] = True
                q.append(temp.right)
        ans += 1
        
    return ans - 1
