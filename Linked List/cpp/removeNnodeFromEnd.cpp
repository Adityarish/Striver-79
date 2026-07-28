// Problem Statement: Given a linked list, and a number N. Find the Nth node from the end of this linked list and delete it.
// Return the head of the new modified linked list.

// Problem Link: https://www.codingninjas.com/studio/problems/delete-kth-node-from-end_799912?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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

Node* removeKthNode(Node* head, int K) {
    if (head == NULL) return head;
    
    int len = getLength(head);
    int dis = len - K;
    int i = 0;
    
    Node* dummy = new Node(-1);
    Node* res = dummy;
    
    while (head->next != NULL && i < dis) {
        res->next = head;
        head = head->next;
        res = res->next;
        i++;
    }
    
    res->next = head->next;
    return dummy->next;
}
