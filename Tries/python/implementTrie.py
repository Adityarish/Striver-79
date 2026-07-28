# Problem Statement: You are given a Trie data structure representing a dictionary of words. You need to implement a function deleteWord that deletes a specified word from the Trie. The Trie is represented by the TrieNode class, which contains an array of children nodes for each letter from 'a' to 'z' and a boolean isEnd indicating whether the current node represents the end of a word.

# Problem Link: https://www.codingninjas.com/studio/problems/trie-delete-operation_1062663?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

def delete_word(root, word):
    curr = root

    for ch in word:
        if curr.children[ord(ch) - ord('a')] is None:
            break
        curr = curr.children[ord(ch) - ord('a')]
    curr.is_end = False
    return root
