// Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).
// What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

// Problem Link: https://www.codingninjas.com/codestudio/problems/number-of-inversions_6840276?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int invCount = 0;

void mergeSort(int arr[], int start, int mid, int end) {
    int size = end - start + 1;
    vector<int> res(size);
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            res[k] = arr[i];
            i++;
            k++;
        } else {
            res[k] = arr[j];
            k++;
            j++;
            // keeping the count of inversions
            invCount += mid - i + 1;
        }
    }

    while (i <= mid) {
        res[k] = arr[i];
        i++;
        k++;
    }

    while (j <= end) {
        res[k] = arr[j];
        k++;
        j++;
    }

    for (int m = start; m <= end; m++) {
        arr[m] = res[m - start];
    }
}

// we will find inversions using merge sort
void merge(int arr[], int start, int end) {
    if (start >= end) return;
    int mid = start + (end - start) / 2;
    merge(arr, start, mid);
    merge(arr, mid + 1, end);
    mergeSort(arr, start, mid, end);
}

int numberOfInversions(int a[], int n) {
    merge(a, 0, n - 1);
    return invCount;
}

int main() {
    int a[] = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions are: " << cnt << endl;
    return 0;
}
