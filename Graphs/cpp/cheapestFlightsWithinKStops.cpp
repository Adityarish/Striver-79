// Problem Statement: There are n cities and m edges connected by some number of flights. You are given an array of flights where flights[i] = [ fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost price. You have also given three integers src, dst, and k, and return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

// Problem Link: https://www.codingninjas.com/studio/problems/saving-money_1171195?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int savingMoney(int n, int source, int destination, int k, vector<vector<int>>& trains) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto& train : trains) {
        adj[train[0]].push_back({train[1], train[2]});
    }

    vector<int> money(n, INT_MAX);
    money[source] = 0;

    queue<pair<int, pair<int, int>>> q; // {stops, {node, cost}}
    q.push({0, {source, 0}});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if (stops > k) continue;

        for (auto& iter : adj[node]) {
            int adjNode = iter.first;
            int edgeWeight = iter.second;

            if (cost + edgeWeight < money[adjNode] && stops <= k) {
                money[adjNode] = cost + edgeWeight;
                q.push({stops + 1, {adjNode, money[adjNode]}});
            }
        }
    }

    if (money[destination] == INT_MAX) return -1;
    return money[destination];
}
