// Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

// Problem Link: https://www.codingninjas.com/codestudio/problems/subarray-with-maximum-product_6890008?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int subarrayWithMaxProduct(vector<int>& arr) {
    int product1 = arr[0];
    int product2 = arr[0];
    int answer = arr[0];

    // loop for finding maximum product using kadane algorithm
    for (int i = 1; i < (int)arr.size(); i++) {
        int res = max(arr[i], max(product1 * arr[i], product2 * arr[i]));
        product2 = min(arr[i], min(product1 * arr[i], product2 * arr[i]));
        product1 = res;

        answer = max(answer, product1);
    }
    return answer;
}

int main() {
    vector<int> nums = {1, 2, -3, 0, -4, -5};
    int answer = subarrayWithMaxProduct(nums);
    cout << "The maximum product subarray is: " << answer << endl;
    return 0;
}
