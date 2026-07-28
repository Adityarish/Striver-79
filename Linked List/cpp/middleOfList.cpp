// Problem Statement: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes,
// return the second middle node.

// Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/

#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

int getLength(ListNode* head) {
    int count = 0;
    while (head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}

ListNode* middleNode(ListNode* head) {
    int len = getLength(head);
    
    if (len % 2 != 0) {
        int i = 1;
        while (head != NULL && i <= len / 2) {
            head = head->next;
            i++;
        }
        return head;
    } else {
        int i = 1;
        while (head != NULL && i < len / 2 + 1) {
            head = head->next;
            i++;
        }
        return head;
    }
}
