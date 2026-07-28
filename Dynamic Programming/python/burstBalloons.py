# Problem Statement: You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array. You are asked to burst all the balloons.
# If you burst the ith balloon, you will get arr[i - 1] * arr[i] * arr[i + 1] coins. If i - 1 or i + 1 goes out of the array's bounds, then treat it as if there is a balloon with a 1 painted on it.
# Return the maximum coins you can collect by bursting the balloons wisely.

# Problem Link: https://www.codingninjas.com/codestudio/problems/burst-balloons_628471?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def burst_balloons(arr):
    n = len(arr)
    balloons = [1] * (n + 2)
    for i in range(n):
        balloons[i + 1] = arr[i]

    dp = [[0] * (n + 2) for _ in range(n + 2)]

    for length in range(1, n + 1):
        for i in range(1, n - length + 2):
            j = i + length - 1
            for k in range(i, j + 1):
                cost = balloons[i - 1] * balloons[k] * balloons[j + 1] + dp[i][k - 1] + dp[k + 1][j]
                dp[i][j] = max(dp[i][j], cost)

    return dp[1][n]
