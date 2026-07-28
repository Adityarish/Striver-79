// Problem Statement: Segregate even and odd nodes in a linked list.

// Problem Link: https://www.codingninjas.com/studio/problems/segregate-even-and-odd-nodes-in-a-linked-list_1116100?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

Node* segregateEvenOdd(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    Node* evenHead = new Node(0);
    Node* oddHead = new Node(0);
    
    Node* even = evenHead;
    Node* odd = oddHead;
    
    Node* current = head;
    
    while (current != NULL) {
        if (current->data % 2 == 0) {
            even->next = current;
            even = even->next;
        } else {
            odd->next = current;
            odd = odd->next;
        }
        current = current->next;
    }
    
    even->next = oddHead->next;
    odd->next = NULL;
    
    return evenHead->next;
}
