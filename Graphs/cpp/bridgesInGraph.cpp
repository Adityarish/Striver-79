// Problem Statement: There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
// A critical connection is a connection that, if removed, will make some servers unable to reach some other servers.
// Return all critical connections in the network in any order.

// Problem Link: https://www.codingninjas.com/studio/problems/bridges-in-a-graph_893026?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void dfs(int node, int parent, int& timer, vector<int>& disc, vector<int>& low,
         vector<vector<int>>& ans, unordered_map<int, vector<int>>& adj,
         vector<bool>& vis) {
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (int neighbor : adj[node]) {
        if (neighbor == parent) {
            continue;
        }

        if (!vis[neighbor]) {
            dfs(neighbor, node, timer, disc, low, ans, adj, vis);
            low[node] = min(low[node], low[neighbor]);

            // Check for bridge edge
            if (low[neighbor] > disc[node]) {
                ans.push_back({node, neighbor});
            }

        } else {
            // Back edge
            low[node] = min(low[node], disc[neighbor]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>>& edges, int v, int e) {
    // Create adjacency list
    unordered_map<int, vector<int>> adj;
    for (const auto& edge : edges) {
        int u = edge[0];
        int w = edge[1];
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    // Create data structures
    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    vector<bool> vis(v, false);

    vector<vector<int>> ans;

    // DFS
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, -1, timer, disc, low, ans, adj, vis);
        }
    }

    return ans;
}
