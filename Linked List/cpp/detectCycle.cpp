// Problem Statement: Given head, the head of a linked list, determine if the linked list has a cycle in it.
//  There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
// Return true if there is a cycle in the linked list. Otherwise, return false.

// Problem Link: https://www.codingninjas.com/studio/problems/cycle-detection-in-a-singly-linked-list_628974?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

bool detectCycle(Node* head) {
    if (head == NULL) {
        return false;
    }
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
    }
    
    return false;
}
