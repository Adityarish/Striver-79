// Problem Statement: Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// Problem Link: https://www.codingninjas.com/studio/problems/combination-sum_981296?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinations(int ind, vector<int>& arr, int target, vector<vector<int>>& res, vector<int>& bs) {
    if (target == 0) {
        res.push_back(bs);
        return;
    }
    if (ind == arr.size() || arr[ind] > target) {
        return;
    }

    // Include the current element in the combination
    bs.push_back(arr[ind]);
    combinations(ind, arr, target - arr[ind], res, bs);
    bs.pop_back();

    // Skip the current element and move to the next one
    combinations(ind + 1, arr, target, res, bs);
}

vector<vector<int>> combSum(vector<int>& ARR, int B) {
    vector<vector<int>> res;
    vector<int> bs;
    sort(ARR.begin(), ARR.end()); // Sort the array to generate combinations efficiently
    combinations(0, ARR, B, res, bs);
    return res;
}
