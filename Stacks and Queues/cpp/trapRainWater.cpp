// Problem Statement: Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain.

// Problem Link: https://leetcode.com/problems/trapping-rain-water/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int trap(vector<int>& arr) {
    int n = arr.size();
    int watertrap = 0;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            int top = st.top();
            st.pop();
            
            if (st.empty()) {
                break;
            }
            
            int distance = i - st.top() - 1;
            int boundedHeight = min(arr[i], arr[st.top()]) - arr[top];
            watertrap += distance * boundedHeight;
        }
        st.push(i);
    }
    
    return watertrap;
}
