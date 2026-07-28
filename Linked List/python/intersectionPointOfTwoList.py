# Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
# If the two linked lists have no intersection at all, return null.

# Problem Link: https://www.codingninjas.com/studio/problems/-intersection-of-two-linked-lists_630457?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class Node:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next

def get_length(head):
    count = 0
    while head:
        count += 1
        head = head.next
    return count

def find_intersection(first_head, second_head):
    # FIRST APPROACH - USING LENGTH VARIABLE
    # first = get_length(first_head)
    # second = get_length(second_head)
    # 
    # while first > second:
    #     first -= 1
    #     first_head = first_head.next
    #     
    # while second > first:
    #     second -= 1
    #     second_head = second_head.next
    #     
    # while first_head and second_head:
    #     if first_head == second_head:
    #         return first_head.data
    #     first_head = first_head.next
    #     second_head = second_head.next
    #     
    # return -1
    
    # SECOND APPROACH - USING DUMMY NODES
    dummy1 = first_head
    dummy2 = second_head
    
    while dummy1 != dummy2:
        dummy1 = second_head if dummy1 is None else dummy1.next
        dummy2 = first_head if dummy2 is None else dummy2.next
        
    if dummy1:
        return dummy1.data
        
    return -1
