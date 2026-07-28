// Problem Statement: Given an unsorted array, print Kth Largest and Smallest Element from an unsorted array.

// Problem Link: https://www.codingninjas.com/codestudio/problems/k-largest-elements_796005?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kLargest(int n, vector<int>& input, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < k; i++) {
        minHeap.push(input[i]);
    }

    for (int i = k; i < n; i++) {
        if (input[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(input[i]);
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}
