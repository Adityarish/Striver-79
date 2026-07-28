# Problem Statement: The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.

# Problem Link: https://www.codingninjas.com/studio/problems/floyd-warshall_2041979?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def floyd_warshall(n, m, src, dest, edges):
    dist = [[float('inf')] * n for _ in range(n)]
    for i in range(n):
        dist[i][i] = 0

    # as it has One-based nodes
    for u, v, wt in edges:
        dist[u - 1][v - 1] = wt

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] != float('inf') and dist[k][j] != float('inf'):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
                    
    ans = dist[src - 1][dest - 1]
    return int(1e9) if ans == float('inf') else ans
