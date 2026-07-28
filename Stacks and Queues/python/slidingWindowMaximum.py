# Problem Statement: Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array to the very right. 
# You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

# Problem Link: https://www.codingninjas.com/studio/problems/sliding-maximum-_701652?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def max_sliding_window(arr, n, k):
    st = []
    nge = [0] * n
    
    st.append(n - 1)
    nge[n - 1] = n
    
    for i in range(n - 2, -1, -1):
        while st and arr[i] >= arr[st[-1]]:
            st.pop()
            
        if not st:
            nge[i] = n
        else:
            nge[i] = st[-1]
            
        st.append(i)
        
    res = []
    j = 0
    
    for i in range(n - k + 1):
        if j < i:
            j = i
        while nge[j] < i + k:
            j = nge[j]
            
        res.append(arr[j])
        
    return res
