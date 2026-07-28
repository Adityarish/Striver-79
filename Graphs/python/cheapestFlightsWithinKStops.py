# Problem Statement: There are n cities and m edges connected by some number of flights. You are given an array of flights where flights[i] = [ fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost price. You have also given three integers src, dst, and k, and return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

# Problem Link: https://www.codingninjas.com/studio/problems/saving-money_1171195?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

from collections import deque
import math

def saving_money(n, source, destination, k, trains):
    adj = [[] for _ in range(n)]
    for u, v, cost in trains:
        adj[u].append((v, cost))

    money = [float('inf')] * n
    money[source] = 0

    # queue stores (stops, node, cost)
    q = deque([(0, source, 0)])

    while q:
        stops, node, cost = q.popleft()

        if stops > k:
            continue

        for adj_node, edge_weight in adj[node]:
            if cost + edge_weight < money[adj_node] and stops <= k:
                money[adj_node] = cost + edge_weight
                q.append((stops + 1, adj_node, money[adj_node]))

    if money[destination] == float('inf'):
        return -1
    return money[destination]
