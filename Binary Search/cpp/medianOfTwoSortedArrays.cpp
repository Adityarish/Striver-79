// Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively,
// return the median of the two sorted arrays.
// The median is defined as the middle value of a sorted list of numbers.
// In case the length of the list is even, the median is the average of the two middle elements.

// Problem Link: https://www.codingninjas.com/codestudio/problems/median-of-two-sorted-arrays_985294?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();

    // if n1 is bigger, swap the arrays
    if (n1 > n2) return median(b, a);

    int n = n1 + n2;  // total length
    int left = (n1 + n2 + 1) / 2;  // length of left half

    // apply binary search
    int low = 0, high = n1;

    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        // calculate l1, l2, r1 and r2
        int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
        int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
        int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
        int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1)
                return max(l1, l2);
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }
    return 0;
}

int main() {
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted arrays is " << median(a, b) << endl;
    return 0;
}
