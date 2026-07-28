# Problem Statement: Given a linked list, and a number N. Find the Nth node from the end of this linked list and delete it.
# Return the head of the new modified linked list.

# Problem Link: https://www.codingninjas.com/studio/problems/delete-kth-node-from-end_799912?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class Node:
    def __init__(self, data=0, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev

def get_length(head):
    count = 0
    while head:
        count += 1
        head = head.next
    return count

def remove_kth_node(head, k):
    if not head:
        return head
        
    length = get_length(head)
    dis = length - k
    i = 0
    
    dummy = Node(-1)
    res = dummy
    
    while head.next and i < dis:
        res.next = head
        head = head.next
        res = res.next
        i += 1
        
    res.next = head.next
    return dummy.next
