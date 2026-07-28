// Problem Statement: Given an array 'arr' of integer numbers, 'arr[i]' represents the number of pages in the 'i-th' book.
// There are 'm' number of students, and the task is to allocate all the books to the students.
// Each student gets at least one book. Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.
// Allocate books such that the maximum number of pages assigned to a student is minimum.
// If the allocation of books is not possible, return -1.

// Problem Link: https://www.codingninjas.com/codestudio/problems/allocate-books_1090540?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int countStudents(vector<int>& arr, int pages) {
    int n = arr.size();
    int students = 1;
    long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            // add pages to current student
            pagesStudent += arr[i];
        } else {
            // add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    // if number of students is greater than number of books
    if (m > n) return -1;
    // low = maximum in array, high = sum of all elements
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            // right part
            low = mid + 1;
        } else {
            // left part
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << endl;
    return 0;
}
