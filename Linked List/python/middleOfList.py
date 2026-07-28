# Problem Statement: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes,
# return the second middle node.

# Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def get_length(head):
    count = 0
    while head:
        head = head.next
        count += 1
    return count

def middle_node(head):
    length = get_length(head)
    
    if length % 2 != 0:
        i = 1
        while head and i <= length // 2:
            head = head.next
            i += 1
        return head
    else:
        i = 1
        while head and i < length // 2 + 1:
            head = head.next
            i += 1
        return head
