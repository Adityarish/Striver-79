// Problem link: https://www.codingninjas.com/codestudio/problems/majority-element_6915220?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> majorityElement(vector<int>& v) {
    int n = v.size(); // size of the array

    int count1 = 0;
    int count2 = 0;
    int element1 = INT_MIN;
    int element2 = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (count1 == 0 && element2 != v[i]) {
            count1 = 1;
            element1 = v[i];
        } else if (count2 == 0 && element1 != v[i]) {
            count2 = 1;
            element2 = v[i];
        } else if (v[i] == element1) {
            count1++;
        } else if (v[i] == element2) {
            count2++;
        } else {
            count1--;
            count2--;
        }
    }

    vector<int> result; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == element1) count1++;
        if (v[i] == element2) count2++;
    }

    int mini = (int)(n / 3) + 1;
    if (count1 >= mini) result.push_back(element1);
    if (count2 >= mini) result.push_back(element2);

    sort(result.begin(), result.end());

    return result;
}

int main() {
    vector<int> v = {1, 1, 1, 2, 2, 3};
    vector<int> ans = majorityElement(v);
    cout << "Majority elements (appearing > n/3 times): ";
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
