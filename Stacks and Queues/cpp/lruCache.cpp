// Problem Statement: "Design a data structure that follows the constraints of Least Recently Used (LRU) cache".
// Implement the LRUCache class:
// LRUCache(int capacity) we need to initialize the LRU cache with positive size capacity.
// int get(int key) returns the value of the key if the key exists, otherwise return -1.
// Void put(int key,int value), Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.if the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// Problem Link: https://www.codingninjas.com/studio/problems/lru-cache-implementation_670276?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
    int capacity;

    void moveToHead(Node* curr) {
        curr->next = head->next;
        curr->prev = head;
        head->next->prev = curr;
        head->next = curr;
    }

    void deleteNode(Node* curr) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (map.find(key) != map.end()) {
            Node* curr = map[key];
            deleteNode(curr);
            moveToHead(curr);
            return curr->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* curr = map[key];
            curr->val = value;
            deleteNode(curr);
            moveToHead(curr);
        } else if (map.size() < capacity) {
            Node* newNode = new Node(key, value);
            map[key] = newNode;
            moveToHead(newNode);
        } else {
            Node* lru = tail->prev;
            map.erase(lru->key);
            deleteNode(lru);
            delete lru;
            
            Node* newNode = new Node(key, value);
            map[key] = newNode;
            moveToHead(newNode);
        }
    }
    
    ~LRUCache() {
        Node* curr = head;
        while (curr != NULL) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};
