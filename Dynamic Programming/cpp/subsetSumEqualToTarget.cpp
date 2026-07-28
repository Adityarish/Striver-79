// Problem Statement: We are given an array 'ARR' with N positive integers. We need to find if there is a subset in "ARR" with a sum equal to K. If there is, return true else return false.

// Problem Link: https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
using namespace std;

bool subsetSumToK(int n, int k, vector<int>& arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }
    
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            bool notTaken = dp[ind - 1][target];
            bool taken = false;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }
            dp[ind][target] = notTaken || taken;
        }
    }
    
    return dp[n - 1][k];
}
