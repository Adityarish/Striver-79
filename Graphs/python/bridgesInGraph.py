# Problem Statement: There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
# A critical connection is a connection that, if removed, will make some servers unable to reach some other servers.
# Return all critical connections in the network in any order.

# Problem Link: https://www.codingninjas.com/studio/problems/bridges-in-a-graph_893026?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

from collections import defaultdict

def dfs(node, parent, timer, disc, low, ans, adj, vis):
    vis[node] = True
    disc[node] = low[node] = timer[0]
    timer[0] += 1

    for neighbor in adj[node]:
        if neighbor == parent:
            continue

        if not vis[neighbor]:
            dfs(neighbor, node, timer, disc, low, ans, adj, vis)
            low[node] = min(low[node], low[neighbor])

            # Check for bridge edge
            if low[neighbor] > disc[node]:
                ans.append([node, neighbor])
        else:
            # Back edge
            low[node] = min(low[node], disc[neighbor])

def find_bridges(edges, v, e):
    # Create adjacency list
    adj = defaultdict(list)
    for u, w in edges:
        adj[u].append(w)
        adj[w].append(u)

    # Create data structures
    timer = [0]
    disc = [-1] * v
    low = [-1] * v
    vis = [False] * v

    ans = []

    # DFS
    for i in range(v):
        if not vis[i]:
            dfs(i, -1, timer, disc, low, ans, adj, vis)

    return ans
