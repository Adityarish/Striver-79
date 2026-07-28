# Problem Statement: You will be given an m x n grid, where each cell has the following values : 
# 2  -  represents a rotten orange
# 1  -  represents a Fresh orange
# 0  -  represents an Empty Cell
# Every minute, if a Fresh Orange is adjacent to a Rotten Orange in 4-direction ( upward, downwards, right, and left ) it becomes Rotten. 
# Return the minimum number of minutes required such that none of the cells has a Fresh Orange. If it's not possible, return -1.

# Problem Link: https://www.codingninjas.com/studio/problems/rotting-oranges_701655?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

from collections import deque

def min_time_to_rot(grid, n, m):
    q = deque()
    visit = [[False] * m for _ in range(n)]
    count_fresh = 0
    
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 2:
                q.append((i, j, 0))
            elif grid[i][j] == 1:
                count_fresh += 1
                
    max_time = 0
    count = 0
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    
    while q:
        row, col, t = q.popleft()
        max_time = max(max_time, t)
        
        for i in range(4):
            new_row = row + dx[i]
            new_col = col + dy[i]
            
            if (0 <= new_row < n and 0 <= new_col < m and 
                grid[new_row][new_col] == 1 and not visit[new_row][new_col]):
                visit[new_row][new_col] = True
                q.append((new_row, new_col, t + 1))
                count += 1
                
    return max_time if count == count_fresh else -1
