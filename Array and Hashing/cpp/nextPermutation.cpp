// Problem Link: https://www.codingninjas.com/codestudio/problems/next-greater-permutation_6929564?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nextGreaterPermutation(vector<int>& A) {
    int n = A.size(); // size of the array

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:
    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

int main() {
    vector<int> A = {1, 3, 2};
    vector<int> ans = nextGreaterPermutation(A);
    cout << "The next permutation is: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
