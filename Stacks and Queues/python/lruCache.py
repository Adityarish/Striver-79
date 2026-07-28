# Problem Statement: "Design a data structure that follows the constraints of Least Recently Used (LRU) cache".
# Implement the LRUCache class:
# LRUCache(int capacity) we need to initialize the LRU cache with positive size capacity.
# int get(int key) returns the value of the key if the key exists, otherwise return -1.
# Void put(int key,int value), Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.if the number of keys exceeds the capacity from this operation, evict the least recently used key.
# The functions get and put must each run in O(1) average time complexity.

# Problem Link: https://www.codingninjas.com/studio/problems/lru-cache-implementation_670276?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class LRUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.map = {}
        self.head = Node(-1, -1)
        self.tail = Node(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head
        
    def _move_to_head(self, curr):
        curr.next = self.head.next
        curr.prev = self.head
        self.head.next.prev = curr
        self.head.next = curr
        
    def _delete_node(self, curr):
        curr.prev.next = curr.next
        curr.next.prev = curr.prev
        
    def get(self, key):
        if key in self.map:
            curr = self.map[key]
            self._delete_node(curr)
            self._move_to_head(curr)
            return curr.val
        return -1
        
    def put(self, key, value):
        if key in self.map:
            curr = self.map[key]
            curr.val = value
            self._delete_node(curr)
            self._move_to_head(curr)
        elif len(self.map) < self.capacity:
            new_node = Node(key, value)
            self.map[key] = new_node
            self._move_to_head(new_node)
        else:
            lru = self.tail.prev
            del self.map[lru.key]
            self._delete_node(lru)
            
            new_node = Node(key, value)
            self.map[key] = new_node
            self._move_to_head(new_node)
