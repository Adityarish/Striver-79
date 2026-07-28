// Problem Statement: Given an integer array nums, return the length of the longest strictly increasing subsequence.

// Problem Link: https://bit.ly/3GuWGpA

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestIncreasingSubsequence(vector<int>& arr) {
    if (arr.empty()) return 0;
    vector<int> lis;
    lis.push_back(arr[0]);
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        if (arr[i] > lis.back()) {
            lis.push_back(arr[i]);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
        }
    }
    return lis.size();
}
