# Problem Statement: Given a linked list. Sort the list in non-decreasing order.

# Problem Link: https://www.codingninjas.com/studio/problems/sort-linked-list_625193?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class Node:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next

def merge(left, right):
    dummy = Node(0)
    current = dummy
    
    while left and right:
        if left.data < right.data:
            current.next = left
            left = left.next
        else:
            current.next = right
            right = right.next
        current = current.next
        
    if left:
        current.next = left
    if right:
        current.next = right
        
    return dummy.next

def find_middle(head):
    if not head:
        return None
        
    slow = head
    fast = head.next
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
    return slow

def sort_list(head):
    if not head or not head.next:
        return head
        
    middle = find_middle(head)
    left = head
    right = middle.next
    middle.next = None
    
    left = sort_list(left)
    right = sort_list(right)
    
    return merge(left, right)
