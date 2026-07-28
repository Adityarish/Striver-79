# Problem Statement: Given a grid of size NxM (N is the number of rows and M is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
# Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

# Problem Link: https://www.codingninjas.com/studio/problems/distinct-islands_630460?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def dfs(arr, temp, i, j, i0, j0):
    if i < 0 or j < 0 or i >= len(arr) or j >= len(arr[0]) or arr[i][j] != 1:
        return
        
    arr[i][j] = 0
    temp.append((i - i0, j - j0))
    
    dfs(arr, temp, i + 1, j, i0, j0)
    dfs(arr, temp, i - 1, j, i0, j0)
    dfs(arr, temp, i, j + 1, i0, j0)
    dfs(arr, temp, i, j - 1, i0, j0)

def distinct_island(arr, n, m):
    unique_islands = set()
    
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 1:
                temp = []
                dfs(arr, temp, i, j, i, j)
                unique_islands.add(tuple(temp))
                
    return len(unique_islands)
