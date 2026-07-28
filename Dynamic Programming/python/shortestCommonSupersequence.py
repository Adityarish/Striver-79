# Problem Statement: Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
# A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

# Problem Link: https://www.codingninjas.com/studio/problems/shortest-supersequence_4244493?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def shortest_supersequence(a, b):
    n = len(a)
    m = len(b)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if a[i - 1] == b[j - 1]:
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                
    ans = []
    i, j = n, m
    while i > 0 and j > 0:
        if a[i - 1] == b[j - 1]:
            ans.append(a[i - 1])
            i -= 1
            j -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            ans.append(a[i - 1])
            i -= 1
        else:
            ans.append(b[j - 1])
            j -= 1
            
    while i > 0:
        ans.append(a[i - 1])
        i -= 1
    while j > 0:
        ans.append(b[j - 1])
        j -= 1
        
    return "".join(reversed(ans))
