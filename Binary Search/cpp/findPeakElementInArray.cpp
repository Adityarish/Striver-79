// Problem Statement: Given an array of length N. Peak element is defined as the element greater than both of its neighbors.
// Formally, if 'arr[i]' is the peak element, 'arr[i-1]' < 'arr[i]' and 'arr[i+1]' < 'arr[i]'.
// Find the index(0-based) of a peak element in the array.
// Note: For the first element, the previous element should be considered as -infinity as well as for the last element.

// Problem Link: https://www.codingninjas.com/codestudio/problems/find-peak-element_1081482?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0; // if length is 0 => no peak element
    if (n == 1) return 0;
    if (arr[0] > arr[1]) {  // check for first element
        return 0;
    }
    if (arr[n - 1] > arr[n - 2]) {  // check for last element
        return n - 1;
    }
    int low = 1;  // we handled both 0 and n-1 cases above
    int high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid;  // if mid is greater than both => mid is peak element
        }
        if (arr[mid] > arr[mid - 1]) {
            low = mid + 1;  // increasing seq. => peak is in right part
        } else {
            high = mid - 1;  // decreasing seq. => peak is in left part
        }
    }
    return -1;  // not found
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << endl;
    return 0;
}
