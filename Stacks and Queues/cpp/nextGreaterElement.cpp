// Problem Statement: Given a circular integer array A, return the next greater element for every element in A. 
// The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn't exist, return -1 for this element.

// Problem Link: https://www.codingninjas.com/studio/problems/next-greater-element_670312?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr, int n) {
    vector<int> nextGreaterEle(n);
    stack<int> st;

    // Push the last element and mark it as -1 because there will be no single
    // greater element than the last one
    st.push(arr[n - 1]);
    nextGreaterEle[n - 1] = -1;

    // Iterate through the array in reverse order
    for (int i = n - 2; i >= 0; i--) {
        // Pop elements from the stack until we find a smaller element or the stack is empty
        while (!st.empty() && arr[i] >= st.top()) {
            st.pop();
        }

        // If the stack is empty, it means the element does not have a greater element
        if (st.empty()) {
            nextGreaterEle[i] = -1;
        } else {
            // There is a greater element because we already removed smaller elements
            nextGreaterEle[i] = st.top();
        }

        // Push the current element onto the stack
        st.push(arr[i]);
    }
    return nextGreaterEle;
}
