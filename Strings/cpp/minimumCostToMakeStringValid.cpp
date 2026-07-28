// Problem Statement: You are given a string consisting of open and close brackets. Your task is to determine the minimum cost required to make the string valid.
// A string is considered valid if and only if:
// It is non-empty.
// Each open bracket '{' must have a corresponding close bracket '}'.
// The brackets must be in pairs and properly nested. For example, '{}' and '{{}}' are valid, but '{', '}{', and '{}}' are not valid.

// Problem Link: https://www.codingninjas.com/studio/problems/minimum-cost-to-make-string-valid_1115770?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int findMinimumCost(string str) {
    if (str.length() % 2 != 0) {
        return -1;
    }
    
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == '{') {
            s.push(ch);
        } else {
            if (!s.empty() && s.top() == '{') {
                s.pop();
            } else {
                s.push(ch);
            }
        }
    }
    
    int openCount = 0, closeCount = 0;
    while (!s.empty()) {
        if (s.top() == '{') {
            openCount++;
        } else {
            closeCount++;
        }
        s.pop();
    }
    
    int cost = (openCount + 1) / 2 + (closeCount + 1) / 2;
    return cost;
}
