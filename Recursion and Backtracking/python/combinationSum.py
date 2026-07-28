# Problem Statement: Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.
# The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

# Problem Link: https://www.codingninjas.com/studio/problems/combination-sum_981296?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def combinations(ind, arr, target, res, bs):
    if target == 0:
        res.append(list(bs))
        return
        
    if ind == len(arr) or arr[ind] > target:
        return
        
    # Include the current element in the combination
    bs.append(arr[ind])
    combinations(ind, arr, target - arr[ind], res, bs)
    bs.pop()
    
    # Skip the current element and move to the next one
    combinations(ind + 1, arr, target, res, bs)

def comb_sum(arr, b):
    res = []
    arr.sort() # Sort the array to generate combinations efficiently
    combinations(0, arr, b, res, [])
    return res
