// Problem Statement: Given a string of alphabetic characters. Return the count of distinct substrings of the string(including the empty string) using the Trie data structure.

// Problem Link: https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    Node* links[26];
    bool isEnd;

    Node() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }

    void add(char chr, Node* node) {
        links[chr - 'a'] = node;
    }

    Node* get(char chr) {
        return links[chr - 'a'];
    }

    bool contains(char chr) {
        return links[chr - 'a'] != nullptr;
    }
};

class Trie {
public:
    Node* root;
    int distinct;

    Trie() {
        root = new Node();
        distinct = 0;
    }

    void insert(string word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++) {
            if (temp->contains(word[i])) {
                temp = temp->get(word[i]);
            } else {
                distinct++;
                temp->add(word[i], new Node());
                temp = temp->get(word[i]);
            }
        }
        temp->isEnd = true;
    }

    int distinctSubstring() {
        return distinct;
    }
};

int countDistinctSubstrings(string s) {
    Trie trie;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        trie.insert(s.substr(i));
    }
    return trie.distinctSubstring() + 1;
}
