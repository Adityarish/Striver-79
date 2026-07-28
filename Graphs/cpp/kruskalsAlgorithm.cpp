// Problem Statement: Given a weighted, undirected, and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

// Problem Link: https://www.codingninjas.com/studio/problems/kruskal%E2%80%99s-minimum-spanning-tree-algorithm_1082553?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Disjoint {
public:
    vector<int> rank, parent;
    Disjoint(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int kruskalMST(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj;
    for (auto& arr : edges) {
        adj.push_back({arr[2], arr[0], arr[1]}); // wt, u, v
    }

    sort(adj.begin(), adj.end());

    Disjoint d(n);
    int sum = 0;

    for (auto& m : adj) {
        int wt = m[0], u = m[1], v = m[2];
        if (d.findParent(u) != d.findParent(v)) {
            sum += wt;
            d.unionByRank(u, v);
        }
    }

    return sum;
}
