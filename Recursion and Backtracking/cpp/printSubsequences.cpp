// Problem Statement: Given a string, find all the possible subsequences of the string.

// Problem Link: https://www.codingninjas.com/studio/problems/print-subsequences_8416366?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> generateSubsequences(string s) {
    if (s.length() == 0) {
        vector<string> bs;
        bs.push_back("");
        return bs;
    }

    char ch = s[0];
    string ss = s.substr(1);

    vector<string> sa = generateSubsequences(ss);
    vector<string> res;

    for (string str : sa) {
        res.push_back(str);
        res.push_back(ch + str);
    }

    return res;
}
