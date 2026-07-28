// Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
// If the two linked lists have no intersection at all, return null.

// Problem Link: https://www.codingninjas.com/studio/problems/-intersection-of-two-linked-lists_630457?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int getLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int findIntersection(Node* firstHead, Node* secondHead) {
    // FIRST APPROACH - USING LENGTH VARIABLE
    /*
    int first = getLength(firstHead);
    int second = getLength(secondHead);
    
    while (first > second) {
        first--;
        firstHead = firstHead->next;
    }
    
    while (second > first) {
        second--;
        secondHead = secondHead->next;
    }
    
    while (firstHead != NULL && secondHead != NULL) {
        if (firstHead == secondHead) {
            return firstHead->data;
        }
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }
    return -1;
    */
    
    // SECOND APPROACH - USING DUMMY NODES
    Node* dummy1 = firstHead;
    Node* dummy2 = secondHead;

    while (dummy1 != dummy2) {
        dummy1 = dummy1 == NULL ? secondHead : dummy1->next;
        dummy2 = dummy2 == NULL ? firstHead : dummy2->next;
    }

    if (dummy1 != NULL) {
        return dummy1->data;
    }
    
    return -1;
}
