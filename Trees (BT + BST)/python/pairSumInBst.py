# Problem Statement: Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

# Problem Link: https://www.codingninjas.com/studio/problems/pair-sum-in-bst._920493?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class TreeNode:
    def __init__(self, data=0, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def pair_sum_bst_using_stacks(root, k):
    if not root:
        return False
        
    left_stack = []
    right_stack = []
    left_curr = root
    right_curr = root
    
    while left_stack or right_stack or left_curr or right_curr:
        while left_curr:
            left_stack.append(left_curr)
            left_curr = left_curr.left
            
        while right_curr:
            right_stack.append(right_curr)
            right_curr = right_curr.right
            
        if not left_stack or not right_stack:
            break
            
        left_node = left_stack[-1]
        right_node = right_stack[-1]
        
        if left_node == right_node:
            break
            
        current_sum = left_node.data + right_node.data
        
        if current_sum == k:
            return True
        elif current_sum < k:
            left_stack.pop()
            left_curr = left_node.right
        else:
            right_stack.pop()
            right_curr = right_node.left
            
    return False

def inorder(root, in_list):
    if not root:
        return
    inorder(root.left, in_list)
    in_list.append(root.data)
    inorder(root.right, in_list)

def pair_sum_bst_using_two_pointer(root, k):
    in_list = []
    inorder(root, in_list)
    
    start = 0
    end = len(in_list) - 1
    
    while start <= end:
        current_sum = in_list[start] + in_list[end]
        if current_sum == k:
            return True
        elif current_sum > k:
            end -= 1
        else:
            start += 1
            
    return False
