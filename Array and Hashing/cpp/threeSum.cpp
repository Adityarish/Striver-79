// Problem Link: https://www.codingninjas.com/codestudio/problems/three-sum_6922132?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> triplet(int n, vector<int>& nums) {
    // sort the array
    sort(nums.begin(), nums.end());
    // make a result list
    vector<vector<int>> res;

    for (int i = 0; i < (int)nums.size() - 2; i++) {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
            int low = i + 1, high = (int)nums.size() - 1;
            int sum = 0 - nums[i];
            while (low < high) {
                if (nums[low] + nums[high] == sum) {
                    res.push_back({nums[i], nums[low], nums[high]});
                    while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;
                    low++;
                    high--;
                } else if (nums[low] + nums[high] < sum) {
                    low++;
                } else {
                    high--;
                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int n = nums.size();
    vector<vector<int>> ans = triplet(n, nums);
    cout << "Triplets that sum to zero:" << endl;
    for (auto& triplet : ans) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    return 0;
}
