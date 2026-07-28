// Problem Statement: Given a grid of size NxM (N is the number of rows and M is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
// Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Problem Link: https://www.codingninjas.com/studio/problems/distinct-islands_630460?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(vector<vector<int>>& arr, vector<pair<int, int>>& temp, int i, int j, int i0, int j0) {
    if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] != 1) {
        return;
    }
    
    arr[i][j] = 0;
    temp.push_back({i - i0, j - j0});
    
    dfs(arr, temp, i + 1, j, i0, j0);
    dfs(arr, temp, i - 1, j, i0, j0);
    dfs(arr, temp, i, j + 1, i0, j0);
    dfs(arr, temp, i, j - 1, i0, j0);
}

int distinctIsland(vector<vector<int>>& arr, int n, int m) {
    set<vector<pair<int, int>>> uniqueIslands;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                vector<pair<int, int>> temp;
                dfs(arr, temp, i, j, i, j);
                uniqueIslands.insert(temp);
            }
        }
    }
    
    return uniqueIslands.size();
}
