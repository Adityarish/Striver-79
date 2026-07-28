# Problem Statement: Given a weighted, undirected, and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

# Problem Link: https://www.codingninjas.com/studio/problems/kruskal%E2%80%99s-minimum-spanning-tree-algorithm_1082553?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class DisjointSet:
    def __init__(self, n):
        self.rank = [0] * (n + 1)
        self.parent = list(range(n + 1))
        
    def find_parent(self, node):
        if node == self.parent[node]:
            return node
        self.parent[node] = self.find_parent(self.parent[node])
        return self.parent[node]
        
    def union_by_rank(self, u, v):
        pu = self.find_parent(u)
        pv = self.find_parent(v)
        
        if self.rank[pu] < self.rank[pv]:
            self.parent[pu] = pv
        elif self.rank[pu] > self.rank[pv]:
            self.parent[pv] = pu
        else:
            self.parent[pv] = pu
            self.rank[pu] += 1

def kruskal_mst(n, edges):
    adj = []
    for u, v, wt in edges:
        adj.append((wt, u, v))
        
    adj.sort()
    
    d = DisjointSet(n)
    mst_sum = 0
    
    for wt, u, v in adj:
        if d.find_parent(u) != d.find_parent(v):
            mst_sum += wt
            d.union_by_rank(u, v)
            
    return mst_sum
