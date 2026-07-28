// Problem Statement: A palindromic string is a string that is equal to its reverse. For example: “Nitin” is a palindromic string. Now the question states to find the length of the longest palindromic subsequence of a string. It is that palindromic subsequence of the given string with the greatest length. We need to print the length of the longest palindromic subsequence.

// Problem Link: https://www.codingninjas.com/studio/problems/longest-palindromic-subsequence_842787?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int helper(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
    if (i == s1.length() || j == s2.length()) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int ans = 0;
    if (s1[i] == s2[j]) {
        ans = 1 + helper(s1, s2, i + 1, j + 1, dp);
    } else {
        ans = max(helper(s1, s2, i + 1, j, dp), helper(s1, s2, i, j + 1, dp));
    }
    return dp[i][j] = ans;
}

int longestPalindromeSubsequence(string s) {
    string ans = s;
    reverse(ans.begin(), ans.end());
    
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return helper(s, ans, 0, 0, dp);
}
