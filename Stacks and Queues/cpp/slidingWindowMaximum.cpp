// Problem Statement: Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array to the very right. 
// You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

// Problem Link: https://www.codingninjas.com/studio/problems/sliding-maximum-_701652?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& arr, int n, int k) {
    stack<int> st;
    vector<int> nge(n);

    // Initialize the stack with the last element of the array
    st.push(n - 1);
    nge[n - 1] = n;

    // Calculate the Next Greater Element (nge) for each element in the array
    for (int i = n - 2; i >= 0; i--) {
        while (!st.empty() && arr[i] >= arr[st.top()]) {
            st.pop();
        }
        if (st.empty()) {
            nge[i] = n;
        } else {
            nge[i] = st.top();
        }
        st.push(i);
    }

    vector<int> res;
    int j = 0;

    // Iterate through the array to find the maximum element in each sliding window
    for (int i = 0; i <= n - k; i++) {
        if (j < i) {
            j = i;
        }
        while (nge[j] < i + k) {
            j = nge[j];
        }
        res.push_back(arr[j]);
    }

    return res;
}
