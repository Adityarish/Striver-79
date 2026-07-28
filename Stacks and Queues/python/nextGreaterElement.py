# Problem Statement: Given a circular integer array A, return the next greater element for every element in A. 
# The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn't exist, return -1 for this element.

# Problem Link: https://www.codingninjas.com/studio/problems/next-greater-element_670312?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def next_greater_element(arr, n):
    next_greater_ele = [-1] * n
    st = []
    
    st.append(arr[n - 1])
    next_greater_ele[n - 1] = -1
    
    for i in range(n - 2, -1, -1):
        while st and arr[i] >= st[-1]:
            st.pop()
            
        if not st:
            next_greater_ele[i] = -1
        else:
            next_greater_ele[i] = st[-1]
            
        st.append(arr[i])
        
    return next_greater_ele
