// Problem Statement: Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with the same color.

// Problem Link: https://www.codingninjas.com/studio/problems/m-coloring-problem_981273?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if it's safe to color a node with a given color
bool isSafe(int node, vector<int>& color, vector<vector<int>>& adjList, int col) {
    for (int it : adjList[node]) {
        if (color[it] == col)
            return false;
    }
    return true;
}

// Function to check graph coloring recursively
bool checkGraphColoring(vector<vector<int>>& adjList, vector<int>& color, int node, int m) {
    if (node == adjList.size())
        return true;

    // Try different colors for the current node
    for (int col = 1; col <= m; col++) {
        if (isSafe(node, color, adjList, col)) {
            color[node] = col;

            // Recursively check the next node
            if (checkGraphColoring(adjList, color, node + 1, m))
                return true;

            color[node] = 0; // Backtrack if no valid coloring is found
        }
    }

    return false;
}

string graphColoring(vector<vector<int>>& mat, int m) {
    int n = mat.size();
    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] != 0)
                adjList[i].push_back(j);
        }
    }

    vector<int> color(n, 0);

    if (checkGraphColoring(adjList, color, 0, m))
        return "YES";
    return "NO";
}
