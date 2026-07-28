# Problem Statement: Given are the two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
# In this problem statement, we need to keep the following conditions in mind:
# A word can only consist of lowercase characters.
# Only one letter can be changed in each transformation.
# Each transformed word must exist in the wordList including the targetWord.
# startWord may or may not be part of the wordList
# Note:  If there's no possible way to transform the sequence from startWord to targetWord return 0.

# Problem Link: https://www.codingninjas.com/studio/problems/word-ladder_1102319?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

from collections import deque

def word_ladder(begin_word, end_word, word_list):
    hs = set(word_list)
    
    q = deque([(begin_word, 1)])
    
    while q:
        word, steps = q.popleft()
        
        if word == end_word:
            return steps
            
        for i in range(len(word)):
            for char_code in range(ord('a'), ord('z') + 1):
                new_word = word[:i] + chr(char_code) + word[i+1:]
                if new_word in hs:
                    q.append((new_word, steps + 1))
                    hs.remove(new_word)
                    
    return -1
