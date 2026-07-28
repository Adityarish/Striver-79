# Problem Statement: We are given an "N*M" matrix of integers. We need to find a path from the top-left corner to the bottom-right corner of the matrix, such that there is a minimum cost past that we select.
# At every cell, we can move in only two directions: right and bottom. The cost of a path is given as the sum of values of cells of the given matrix.

# Problem Link: https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def min_sum_path(grid):
    if not grid or not grid[0]:
        return 0
        
    n = len(grid)
    m = len(grid[0])
    dp = [[0] * m for _ in range(n)]
    
    for i in range(n - 1, -1, -1):
        for j in range(m - 1, -1, -1):
            if i == n - 1 and j == m - 1:
                dp[i][j] = grid[i][j]
            elif i == n - 1:
                dp[i][j] = dp[i][j + 1] + grid[i][j]
            elif j == m - 1:
                dp[i][j] = dp[i + 1][j] + grid[i][j]
            else:
                dp[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j])
                
    return dp[0][0]
