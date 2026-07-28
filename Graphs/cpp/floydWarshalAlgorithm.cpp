// Problem Statement: The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.

// Problem Link: https://www.codingninjas.com/studio/problems/floyd-warshall_2041979?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>>& edges) {
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // as it has One-based nodes
    for (auto& it : edges) {
        int u = it[0] - 1;
        int v = it[1] - 1;
        int wt = it[2];
        dist[u][v] = wt;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != 1e9 && dist[k][j] != 1e9) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    return dist[src - 1][dest - 1] == 1e9 ? 1000000000 : dist[src - 1][dest - 1];
}
