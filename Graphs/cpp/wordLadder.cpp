// Problem Statement: Given are the two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
// In this problem statement, we need to keep the following conditions in mind:
// A word can only consist of lowercase characters.
// Only one letter can be changed in each transformation.
// Each transformed word must exist in the wordList including the targetWord.
// startWord may or may not be part of the wordList
// Note:  If there's no possible way to transform the sequence from startWord to targetWord return 0.

// Problem Link: https://www.codingninjas.com/studio/problems/word-ladder_1102319?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

int wordLadder(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> hs(wordList.begin(), wordList.end());
    
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    
    while (!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        if (word == endWord) return steps;
        
        for (int i = 0; i < word.length(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (hs.find(word) != hs.end()) {
                    q.push({word, steps + 1});
                    hs.erase(word);
                }
            }
            word[i] = original;
        }
    }
    
    return -1;
}
