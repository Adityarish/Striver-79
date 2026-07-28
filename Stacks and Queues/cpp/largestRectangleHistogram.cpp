// Problem Statement: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1  return the area of the largest rectangle in histogram.

// Problem Link: https://www.codingninjas.com/studio/problems/largest-rectangle-in-a-histogram_1058184?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangle(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    vector<int> lb(n);
    vector<int> rb(n);

    // Calculate left boundaries
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if (st.empty()) {
            lb[i] = 0;
        } else {
            lb[i] = st.top() + 1;
        }
        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

    // Calculate right boundaries
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if (st.empty()) {
            rb[i] = n - 1;
        } else {
            rb[i] = st.top() - 1;
        }

        st.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = (rb[i] - lb[i] + 1);
        maxArea = max(maxArea, heights[i] * width);
    }
    return maxArea;
}
