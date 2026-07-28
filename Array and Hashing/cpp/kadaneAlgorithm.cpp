// Problem link : https://bit.ly/3HZltTa

#include <iostream>
#include <climits>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    if (n == 0) return 0;
    if (arr == nullptr) return 0;

    long long meh = 0;
    // maximum sum so far
    long long msf = INT_MIN;

    for (int i = 0; i < n; i++) {
        meh = meh + arr[i];
        if (meh < arr[i])
            meh = arr[i];
        if (meh > msf)
            msf = meh;
        // if maximum sum so far becomes negative at
        // any point we just initialize it as zero
        if (msf < 0)
            msf = 0;
    }
    // return maximum sum
    return msf;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The maximum subarray sum is: " << maxSubarraySum(arr, n) << endl;
    return 0;
}
