// Problem Statement: Given a linked list. Sort the list in non-decreasing order.

// Problem Link: https://www.codingninjas.com/studio/problems/sort-linked-list_625193?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

Node* merge(Node* left, Node* right) {
    Node* dummy = new Node(0);
    Node* current = dummy;
    
    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            current->next = left;
            left = left->next;
        } else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }
    
    if (left != NULL) {
        current->next = left;
    }
    
    if (right != NULL) {
        current->next = right;
    }
    
    return dummy->next;
}

Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head->next;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

Node* sortList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    Node* middle = findMiddle(head);
    Node* left = head;
    Node* right = middle->next;
    middle->next = NULL;
    
    left = sortList(left);
    right = sortList(right);
    
    return merge(left, right);
}
