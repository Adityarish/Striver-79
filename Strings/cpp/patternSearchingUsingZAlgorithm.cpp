// Problem Statement: You are given a string text and a pattern pattern. Your task is to find all occurrences of the pattern in the given text using the Z-Algorithm.

// Problem Link: https://www.codingninjas.com/codestudio/problems/pattern-searching-using-z-algorithm_8395752?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> search(string s, string pattern) {
    vector<int> v;
    int n = s.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        for (; j < m; j++) {
            if (s[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            v.push_back(i + 1);
        }
    }
    return v;
}
