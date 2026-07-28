// Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.
// Problem Link: https://www.codingninjas.com/codestudio/problems/subarrays-with-xor-k_6826258?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysWithSumK(vector<int>& a, int b) {
    int n = a.size(); // size of the given array.
    int xr = 0;
    unordered_map<int, int> mp; // declaring the map.
    mp[xr] = 1; // setting the value of 0.
    int count = 0;

    for (int i = 0; i < n; i++) {
        // prefix xor till index i:
        xr = xr ^ a[i];

        // By formula: x = xr ^ b:
        int x = xr ^ b;

        // add the occurrence of xr^k to the count:
        if (mp.find(x) != mp.end()) {
            count += mp[x];
        }

        // Insert the prefix xor till index i into the map:
        mp[xr]++;
    }
    return count;
}

int main() {
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithSumK(a, k);
    cout << "The number of subarrays with XOR k is: " << ans << endl;
    return 0;
}
