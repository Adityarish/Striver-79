// Problem Statement: You are given a sorted array 'arr' of length 'n', which contains positive integer positions of 'n' gas stations.
// You are also given an integer 'k'. Place 'k' new gas stations on the X-axis.
// Find the minimum value of the maximum distance between adjacent gas stations after adding k new gas stations.

// Problem Link: https://www.codingninjas.com/codestudio/problems/minimise-max-distance_7541449?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numberOfGasStationsRequired(double distance, vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = (int)((arr[i] - arr[i - 1]) / distance);
        if ((arr[i] - arr[i - 1]) == (distance * numberInBetween)) {
            numberInBetween--;
        }
        count += numberInBetween;
    }
    return count;
}

double minimiseMaxDistance(vector<int>& arr, int K) {
    int n = arr.size();
    double low = 0;
    double high = 0;

    // Find the maximum distance
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (double)(arr[i + 1] - arr[i]));
    }

    double differ = 1e-6;
    while (high - low > differ) {
        double mid = (low + high) / 2.0;
        int count = numberOfGasStationsRequired(mid, arr);
        if (count > K) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << endl;
    return 0;
}
