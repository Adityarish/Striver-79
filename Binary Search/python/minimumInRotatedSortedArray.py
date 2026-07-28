# Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values).
# The array is rotated between 1 to N times. Find the minimum element in the array.

# Problem Link: https://www.codingninjas.com/codestudio/problems/rotated-array_1093219?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

import math


def find_min(arr):
    low = 0
    high = len(arr) - 1
    res = math.inf
    while low <= high:
        mid = (low + high) // 2
        if arr[low] <= arr[high]:
            res = min(res, arr[low])
            break
        # if left part is sorted
        if arr[low] <= arr[mid]:
            # keep the minimum
            res = min(res, arr[low])
            # Eliminate left half
            low = mid + 1
        else:
            # if right part is sorted
            # keep the minimum
            res = min(res, arr[mid])
            # Eliminate right half
            high = mid - 1
    return res


if __name__ == "__main__":
    arr = [4, 5, 6, 7, 0, 1, 2, 3]
    ans = find_min(arr)
    print(f"The minimum element is: {ans}")
