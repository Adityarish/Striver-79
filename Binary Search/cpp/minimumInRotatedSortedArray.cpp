// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values).
// The array is rotated between 1 to N times. Find the minimum element in the array.

// Problem Link: https://www.codingninjas.com/codestudio/problems/rotated-array_1093219?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int findMin(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;
    int res = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high]) {
            res = min(res, arr[low]);
            break;
        }
        // if left part is sorted
        if (arr[low] <= arr[mid]) {
            // keep the minimum
            res = min(res, arr[low]);
            // Eliminate left half
            low = mid + 1;
        } else {
            // if right part is sorted
            // keep the minimum
            res = min(res, arr[mid]);
            // Eliminate right half
            high = mid - 1;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << endl;
    return 0;
}
