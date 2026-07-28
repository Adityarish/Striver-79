# Problem Statement: Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain.

# Problem Link: https://leetcode.com/problems/trapping-rain-water/

def trap(arr):
    n = len(arr)
    watertrap = 0
    st = []
    
    for i in range(n):
        while st and arr[i] > arr[st[-1]]:
            top = st.pop()
            
            if not st:
                break
                
            distance = i - st[-1] - 1
            bounded_height = min(arr[i], arr[st[-1]]) - arr[top]
            watertrap += distance * bounded_height
            
        st.append(i)
        
    return watertrap
