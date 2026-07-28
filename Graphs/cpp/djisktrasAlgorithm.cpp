// Problem Statement: Given a weighted, undirected, and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is an edge between i and j, second integers corresponds to the weight of that edge. You are given the source vertex S and You have to Find the shortest distance of all the vertex from the source vertex S. You have to return a list of integers denoting the shortest distance between each node and Source vertex S.
// Note: The Graph doesn't contain any negative weight cycle

// Problem Link: https://www.codingninjas.com/studio/problems/dijkstra's-shortest-path_985358?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(vector<vector<int>>& edge, int v, int edges, int source) {
    vector<vector<pair<int, int>>> adj(v);
    
    for (int i = 0; i < edges; i++) {
        adj[edge[i][0]].push_back({edge[i][1], edge[i][2]});
        adj[edge[i][1]].push_back({edge[i][0], edge[i][2]});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v, INT_MAX);
    
    dist[source] = 0;
    pq.push({0, source}); // {dist, node}
    
    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (dis > dist[node]) {
            continue;
        }
        
        for (auto& it : adj[node]) {
            int adjNode = it.first;
            int wt = it.second;
            
            if (dis + wt < dist[adjNode]) {
                dist[adjNode] = dis + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    
    vector<int> shortestDistances;
    for (int d : dist) {
        if (d == INT_MAX) {
            shortestDistances.push_back(-1);
        } else {
            shortestDistances.push_back(d);
        }
    }
    return shortestDistances;
}
