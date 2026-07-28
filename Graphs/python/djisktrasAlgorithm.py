# Problem Statement: Given a weighted, undirected, and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is an edge between i and j, second integers corresponds to the weight of that edge. You are given the source vertex S and You have to Find the shortest distance of all the vertex from the source vertex S. You have to return a list of integers denoting the shortest distance between each node and Source vertex S.
# Note: The Graph doesn't contain any negative weight cycle

# Problem Link: https://www.codingninjas.com/studio/problems/dijkstra's-shortest-path_985358?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

import heapq

def dijkstra(edge, v, edges, source):
    adj = [[] for _ in range(v)]
    for i in range(edges):
        adj[edge[i][0]].append((edge[i][1], edge[i][2]))
        adj[edge[i][1]].append((edge[i][0], edge[i][2]))
        
    pq = []
    heapq.heappush(pq, (0, source))  # (distance, node)
    
    dist = [float('inf')] * v
    dist[source] = 0
    
    while pq:
        dis, node = heapq.heappop(pq)
        
        if dis > dist[node]:
            continue
            
        for adj_node, wt in adj[node]:
            if dis + wt < dist[adj_node]:
                dist[adj_node] = dis + wt
                heapq.heappush(pq, (dist[adj_node], adj_node))
                
    shortest_distances = []
    for d in dist:
        if d == float('inf'):
            shortest_distances.append(-1)
        else:
            shortest_distances.append(d)
            
    return shortest_distances
