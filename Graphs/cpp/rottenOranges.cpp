// Problem Statement: You will be given an m x n grid, where each cell has the following values : 
// 2  -  represents a rotten orange
// 1  -  represents a Fresh orange
// 0  -  represents an Empty Cell
// Every minute, if a Fresh Orange is adjacent to a Rotten Orange in 4-direction ( upward, downwards, right, and left ) it becomes Rotten. 
// Return the minimum number of minutes required such that none of the cells has a Fresh Orange. If it's not possible, return -1.

// Problem Link: https://www.codingninjas.com/studio/problems/rotting-oranges_701655?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Pair {
public:
    int row, col, time;
    Pair(int r, int c, int t) : row(r), col(c), time(t) {}
};

int minTimeToRot(vector<vector<int>>& grid, int n, int m) {
    queue<Pair> q;
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    int countFresh = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push(Pair(i, j, 0));
            } else if (grid[i][j] == 1) {
                countFresh++;
            }
        }
    }

    int maxTime = 0;
    int count = 0;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while (!q.empty()) {
        Pair curr = q.front();
        q.pop();
        
        int row = curr.row;
        int col = curr.col;
        int t = curr.time;
        maxTime = max(maxTime, t);

        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && 
                grid[newRow][newCol] == 1 && !visit[newRow][newCol]) {
                visit[newRow][newCol] = true;
                q.push(Pair(newRow, newCol, t + 1));
                count++;
            }
        }
    }

    return count != countFresh ? -1 : maxTime;
}
