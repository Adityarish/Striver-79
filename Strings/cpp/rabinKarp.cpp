// Problem Statement: You are given a text string and a pattern string. Your task is to find all occurrences of the pattern in the given text using the Rabin-Karp string matching algorithm.

// Problem Link: https://www.codingninjas.com/codestudio/problems/stringmatch-rabincarp_1115738?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> stringMatch(string text, string pattern) {
    vector<int> ans;
    int n = text.length();
    int m = pattern.length();
    
    for (int i = 0; i <= n - m; i++) {
        if (text.substr(i, m) == pattern) {
            ans.push_back(i + 1);
        }
    }
    return ans;
}
