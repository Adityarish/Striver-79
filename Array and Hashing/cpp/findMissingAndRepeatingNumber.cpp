// Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive.
// Each integer appears exactly once except A which appears twice and B which is missing.
// The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

// Problem Link: https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_6828164?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int>& arr) {
    long long n = arr.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 = val2 / val1;

    long long a = (val1 + val2) / 2;
    long long b = a - val1;

    return {(int)a, (int)b};
}

int main() {
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}" << endl;
    return 0;
}
