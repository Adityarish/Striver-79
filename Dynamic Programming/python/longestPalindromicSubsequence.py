# Problem Statement: A palindromic string is a string that is equal to its reverse. For example: “Nitin” is a palindromic string. Now the question states to find the length of the longest palindromic subsequence of a string. It is that palindromic subsequence of the given string with the greatest length. We need to print the length of the longest palindromic subsequence.

# Problem Link: https://www.codingninjas.com/studio/problems/longest-palindromic-subsequence_842787?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def helper(s1, s2, i, j, dp):
    if i == len(s1) or j == len(s2):
        return 0
    if dp[i][j] != -1:
        return dp[i][j]
        
    ans = 0
    if s1[i] == s2[j]:
        ans = 1 + helper(s1, s2, i + 1, j + 1, dp)
    else:
        ans = max(helper(s1, s2, i + 1, j, dp), helper(s1, s2, i, j + 1, dp))
        
    dp[i][j] = ans
    return ans

def longest_palindrome_subsequence(s):
    ans = s[::-1]
    n = len(s)
    dp = [[-1 for _ in range(n)] for _ in range(n)]
    return helper(s, ans, 0, 0, dp)
