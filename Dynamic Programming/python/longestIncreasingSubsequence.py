# Problem Statement: Given an integer array nums, return the length of the longest strictly increasing subsequence.

# Problem Link: https://bit.ly/3GuWGpA

import bisect

def longest_increasing_subsequence(arr):
    if not arr:
        return 0
    lis = [arr[0]]
    for i in range(1, len(arr)):
        if arr[i] > lis[-1]:
            lis.append(arr[i])
        else:
            index = bisect.bisect_left(lis, arr[i])
            lis[index] = arr[i]
    return len(lis)
