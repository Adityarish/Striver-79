# Problem Statement: You are given a text string and a pattern string. Your task is to find all occurrences of the pattern in the given text using the Rabin-Karp string matching algorithm.

# Problem Link: https://www.codingninjas.com/codestudio/problems/stringmatch-rabincarp_1115738?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def string_match(text, pattern):
    ans = []
    n = len(text)
    m = len(pattern)
    
    for i in range(n - m + 1):
        if text[i:i+m] == pattern:
            ans.append(i + 1)
            
    return ans
