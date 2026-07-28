// Problem Statement: Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

// Problem Link: https://www.codingninjas.com/studio/problems/shortest-supersequence_4244493?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string shortestSupersequence(string a, string b) {
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans += a[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            ans += a[i - 1];
            i--;
        } else {
            ans += b[j - 1];
            j--;
        }
    }
    
    while (i > 0) {
        ans += a[i - 1];
        i--;
    }
    while (j > 0) {
        ans += b[j - 1];
        j--;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}
