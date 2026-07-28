// Problem Statement: A Ninja has an 'N' Day training schedule. He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. There are merit points associated with performing an activity each day. The same activity can't be performed on two consecutive days. We need to find the maximum merit points the ninja can attain in N Days.
// We are given a 2D Array POINTS of size 'N*3' which tells us the merit point of specific activity on that particular day. Our task is to calculate the maximum number of merit points that the ninja can earn.

// Problem Link: https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ninjaTraining(int n, vector<vector<int>>& points) {
    if (n == 0) return 0;
    
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(max(points[0][0], points[0][1]), points[0][2]);

    for (int day = 1; day < n; day++) {
        for (int last = 0; last <= 3; last++) {
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    dp[day][last] = max(dp[day][last], points[day][task] + dp[day - 1][task]);
                }
            }
        }
    }
    return dp[n - 1][3];
}
