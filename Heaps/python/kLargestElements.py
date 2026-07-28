# Problem Statement: Given an unsorted array, print Kth Largest and Smallest Element from an unsorted array.

# Problem Link: https://www.codingninjas.com/codestudio/problems/k-largest-elements_796005?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

import heapq

def k_largest(n, input_arr, k):
    min_heap = []
    
    for i in range(k):
        heapq.heappush(min_heap, input_arr[i])
        
    for i in range(k, n):
        if input_arr[i] > min_heap[0]:
            heapq.heappop(min_heap)
            heapq.heappush(min_heap, input_arr[i])
            
    result = []
    while min_heap:
        result.append(heapq.heappop(min_heap))
        
    return result
