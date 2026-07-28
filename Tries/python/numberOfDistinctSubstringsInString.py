# Problem Statement: Given a string of alphabetic characters. Return the count of distinct substrings of the string(including the empty string) using the Trie data structure.

# Problem Link: https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class Node:
    def __init__(self):
        self.links = [None] * 26
        self.is_end = False

    def add(self, ch, node):
        self.links[ord(ch) - ord('a')] = node

    def get(self, ch):
        return self.links[ord(ch) - ord('a')]

    def contains(self, ch):
        return self.links[ord(ch) - ord('a')] is not None

class Trie:
    def __init__(self):
        self.root = Node()
        self.distinct = 0

    def insert(self, word):
        temp = self.root
        for ch in word:
            if temp.contains(ch):
                temp = temp.get(ch)
            else:
                self.distinct += 1
                temp.add(ch, Node())
                temp = temp.get(ch)
        temp.is_end = True

    def distinct_substring(self):
        return self.distinct

def count_distinct_substrings(s):
    trie = Trie()
    n = len(s)
    for i in range(n):
        trie.insert(s[i:])
    return trie.distinct_substring() + 1
