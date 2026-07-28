# Problem Statement: Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with the same color.

# Problem Link: https://www.codingninjas.com/studio/problems/m-coloring-problem_981273?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def is_safe(node, color, adj_list, col):
    for neighbor in adj_list[node]:
        if color[neighbor] == col:
            return False
    return True

def check_graph_coloring(adj_list, color, node, m):
    if node == len(adj_list):
        return True
        
    for col in range(1, m + 1):
        if is_safe(node, color, adj_list, col):
            color[node] = col
            
            if check_graph_coloring(adj_list, color, node + 1, m):
                return True
                
            color[node] = 0
            
    return False

def graph_coloring(mat, m):
    n = len(mat)
    adj_list = [[] for _ in range(n)]
    
    for i in range(n):
        for j in range(len(mat[i])):
            if mat[i][j] != 0:
                adj_list[i].append(j)
                
    color = [0] * n
    
    if check_graph_coloring(adj_list, color, 0, m):
        return "YES"
    return "NO"
