# Problem Statement: Segregate even and odd nodes in a linked list.

# Problem Link: https://www.codingninjas.com/studio/problems/segregate-even-and-odd-nodes-in-a-linked-list_1116100?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class Node:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next

def segregate_even_odd(head):
    if not head or not head.next:
        return head
        
    even_head = Node(0)
    odd_head = Node(0)
    
    even = even_head
    odd = odd_head
    
    current = head
    
    while current:
        if current.data % 2 == 0:
            even.next = current
            even = even.next
        else:
            odd.next = current
            odd = odd.next
        current = current.next
        
    even.next = odd_head.next
    odd.next = None
    
    return even_head.next
