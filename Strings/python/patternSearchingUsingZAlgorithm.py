# Problem Statement: You are given a string text and a pattern pattern. Your task is to find all occurrences of the pattern in the given text using the Z-Algorithm.

# Problem Link: https://www.codingninjas.com/codestudio/problems/pattern-searching-using-z-algorithm_8395752?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def search(s, pattern):
    v = []
    n = len(s)
    m = len(pattern)
    
    for i in range(n - m + 1):
        j = 0
        while j < m:
            if s[i + j] != pattern[j]:
                break
            j += 1
            
        if j == m:
            v.append(i + 1)
            
    return v
