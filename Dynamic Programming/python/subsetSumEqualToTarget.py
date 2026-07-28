# Problem Statement: We are given an array 'ARR' with N positive integers. We need to find if there is a subset in "ARR" with a sum equal to K. If there is, return true else return false.

# Problem Link: https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def subset_sum_to_k(n, k, arr):
    dp = [[False] * (k + 1) for _ in range(n)]
    
    for i in range(n):
        dp[i][0] = True
        
    if arr[0] <= k:
        dp[0][arr[0]] = True
        
    for ind in range(1, n):
        for target in range(1, k + 1):
            not_taken = dp[ind - 1][target]
            taken = False
            if arr[ind] <= target:
                taken = dp[ind - 1][target - arr[ind]]
            dp[ind][target] = not_taken or taken
            
    return dp[n - 1][k]
