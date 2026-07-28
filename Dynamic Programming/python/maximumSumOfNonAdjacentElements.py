# Problem Statement:Given an array of 'N'  positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.
# Note: A subsequence of an array is a list with elements of the array where some elements are deleted ( or not deleted at all) and the elements should be in the same order in the subsequence as in the array.

# Problem Link: https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def maximum_non_adjacent_sum(nums):
    if not nums:
        return 0
        
    exc = 0
    inc = nums[0]
    
    for i in range(1, len(nums)):
        ninc = exc + nums[i]
        nexc = max(exc, inc)
        exc = nexc
        inc = ninc
        
    return max(exc, inc)
