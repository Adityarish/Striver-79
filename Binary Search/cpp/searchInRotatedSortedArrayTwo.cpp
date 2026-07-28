// Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicates)
// and a target value k. The array is rotated at some pivot point. Return true if k is present, otherwise return false.

// Problem Link: https://www.codingninjas.com/codestudio/problems/search-in-a-rotated-sorted-array-ii_7449547?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int>& A, int key) {
    // We will be using binary search
    int low = 0;
    int high = A.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        // if mid element is key => element found
        if (A[mid] == key) {
            return true;
        }
        // if elements are duplicated
        if (A[low] == A[mid] && A[mid] == A[high]) {
            low++;
            high--;
            continue;
        }
        // find range in which key element is present
        if (A[low] <= A[mid]) {
            // if element is present in first half => shrink array
            if (A[low] <= key && key <= A[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (A[mid] <= key && key <= A[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = searchInARotatedSortedArrayII(arr, k);
    if (!ans)
        cout << "Target is not present." << endl;
    else
        cout << "Target is present in the array." << endl;
    return 0;
}
