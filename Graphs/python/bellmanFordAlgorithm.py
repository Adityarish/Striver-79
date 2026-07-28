# Problem Statement: Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertices from the source vertex S.
# Note: If the Graph contains a negative cycle then return an array consisting of only -1.

# Problem Link: https://www.codingninjas.com/studio/problems/bellman-ford_2041977?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def bellmon_ford(n, m, src, edges):
    dist = [int(1e8)] * (n + 1)
    dist[src] = 0
    
    for i in range(1, n):
        for j in range(m):
            u = edges[j][0]
            v = edges[j][1]
            d = edges[j][2]
            if dist[u] + d < dist[v]:
                dist[v] = dist[u] + d
                
    return dist
