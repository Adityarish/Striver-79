// Problem Statement: A monkey is given 'n' piles of bananas, where the 'ith' pile has 'a[i]' bananas.
// An integer 'h' is also given, which denotes the time (in hours) for all the bananas to be eaten.
// Find the minimum number of bananas 'k' to eat per hour so that the monkey can eat all the bananas within 'h' hours.

// Problem Link: https://www.codingninjas.com/codestudio/problems/minimum-rate-to-eat-bananas_7449064?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int totalHours(vector<int>& v, int hours) {
    int total = 0;
    for (int bananas : v) {
        total += (int)ceil((double)bananas / (double)hours);
    }
    return total;
}

int maxBananas(vector<int>& v) {
    return *max_element(v.begin(), v.end());
}

int minimumRateToEatBananas(vector<int>& v, int h) {
    int low = 1;
    int high = maxBananas(v);
    while (low <= high) {
        int mid = (low + high) / 2;
        int total = totalHours(v, mid);
        if (total <= h) {  // min can be found in left part
            high = mid - 1;
        } else {
            low = mid + 1;  // min can be found in right part
        }
    }
    return low;
}

int main() {
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat at least " << ans << " bananas/hr." << endl;
    return 0;
}
