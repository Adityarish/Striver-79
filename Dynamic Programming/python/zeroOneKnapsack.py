# Problem Statement: A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items. Its weight is given by the ‘wt’ array and its value by the ‘val’ array. He can either include an item in its knapsack or exclude it. Check if all the items are unique and return the maximum value he can steal.

# Problem Link: https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def knapsack(weight, value, n, max_weight):
    prev = [0] * (max_weight + 1)
    
    for w in range(weight[0], max_weight + 1):
        prev[w] = value[0]
        
    for ind in range(1, n):
        curr = [0] * (max_weight + 1)
        for w in range(max_weight + 1):
            not_take = prev[w]
            take = -float('inf')
            if weight[ind] <= w:
                take = value[ind] + prev[w - weight[ind]]
            curr[w] = max(not_take, take)
        prev = curr
        
    return prev[max_weight]
