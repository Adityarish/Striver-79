// Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls.
// You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.

// Problem Link: https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canWePlace(vector<int>& arr, int distance, int cows) {
    // we assume we already placed one cow
    int countCows = 1;
    // position where last cow was placed
    int lastCow = arr[0];
    for (int i = 1; i < (int)arr.size(); i++) {
        if (arr[i] - lastCow >= distance) {
            // increase count of cow
            countCows++;
            // position of ith cow
            lastCow = arr[i];
        }
        // if we placed all desired cows we can return true
        if (countCows >= cows) {
            return true;
        }
    }
    return false;
}

int aggressiveCow(vector<int>& stalls, int k) {
    // sort the array
    sort(stalls.begin(), stalls.end());
    int low = 0;
    int high = stalls[stalls.size() - 1] - stalls[0];
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k)) {
            // if it is possible to place cow at mid, we can go to right
            // because we want maximum and we will get max on right else it will be on left
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    // high will be at maximum distance we can get
    return high;
}

int main() {
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCow(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << endl;
    return 0;
}
