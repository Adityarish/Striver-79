# Problem Statement: You are given a string text and a pattern pattern. Your task is to find the starting index of the first occurrence of the pattern in the given text using the Knuth-Morris-Pratt (KMP) algorithm.

# Problem Link: https://www.codingninjas.com/codestudio/problems/search-pattern-kmp-algorithm_8416386?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def string_match(text, pattern):
    n = len(text)
    m = len(pattern)
    ans = []
    lps = [0] * m
    length = 0
    
    i = 1
    while i < m:
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
                
    i = 0
    j = 0
    while i < n:
        if text[i] == pattern[j]:
            i += 1
            j += 1
            if j == m:
                ans.append(i - j + 1)
                j = lps[j - 1]
        else:
            if j > 0:
                j = lps[j - 1]
            else:
                i += 1
                
    return ans
