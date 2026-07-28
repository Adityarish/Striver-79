# Problem Statement: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1  return the area of the largest rectangle in histogram.

# Problem Link: https://www.codingninjas.com/studio/problems/largest-rectangle-in-a-histogram_1058184?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def largest_rectangle(heights):
    n = len(heights)
    st = []
    lb = [0] * n
    rb = [0] * n

    # Calculate left boundaries
    for i in range(n):
        while st and heights[st[-1]] >= heights[i]:
            st.pop()

        if not st:
            lb[i] = 0
        else:
            lb[i] = st[-1] + 1
        st.append(i)

    st = []

    # Calculate right boundaries
    for i in range(n - 1, -1, -1):
        while st and heights[st[-1]] >= heights[i]:
            st.pop()

        if not st:
            rb[i] = n - 1
        else:
            rb[i] = st[-1] - 1
            
        st.append(i)

    max_area = 0
    for i in range(n):
        width = rb[i] - lb[i] + 1
        max_area = max(max_area, heights[i] * width)
        
    return max_area
