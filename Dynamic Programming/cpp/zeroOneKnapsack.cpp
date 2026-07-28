// Problem Statement: A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items. Its weight is given by the ‘wt’ array and its value by the ‘val’ array. He can either include an item in its knapsack or exclude it. Check if all the items are unique and return the maximum value he can steal.

// Problem Link: https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
    vector<int> prev(maxWeight + 1, 0);
    
    for (int w = weight[0]; w <= maxWeight; w++) {
        prev[w] = value[0];
    }
    
    for (int ind = 1; ind < n; ind++) {
        vector<int> curr(maxWeight + 1, 0);
        for (int w = 0; w <= maxWeight; w++) {
            int notTake = prev[w];
            int take = -1e9;
            if (weight[ind] <= w) {
                take = value[ind] + prev[w - weight[ind]];
            }
            curr[w] = max(notTake, take);
        }
        prev = curr;
    }
    
    return prev[maxWeight];
}
