// Problem Statement: We are given an array Arr[] of length n. It represents the price of a stock on 'n' days. The following guidelines need to be followed:
// We can buy and sell the stock any number of times.
// In order to sell the stock, we need to first buy it on the same or any previous day.
// We can't buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can't sell before buying and can't buy before selling any previously bought stock.
// We can do at-most K transactions.

// Problem Link: https://www.codingninjas.com/studio/problems/best-time-to-buy-and-sell-stock-iv_1080698?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumProfit(vector<int>& prices, int n, int k) {
    vector<int> dp(2 * k + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int t = 0; t < 2 * k; t++) {
            if (t % 2 == 0)
                dp[t] = max(dp[t + 1] - prices[i], dp[t]);
            else
                dp[t] = max(dp[t + 1] + prices[i], dp[t]);
        }
    }
    return dp[0];
}
