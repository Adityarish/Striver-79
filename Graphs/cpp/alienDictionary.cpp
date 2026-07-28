// Problem Statement: Given a sorted dictionary of an alien language having N words and k starting alphabets of a standard dictionary. Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order.

// Problem Link: https://www.codingninjas.com/studio/problems/alien-dictionary_630423?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj, stack<int>& st) {
    vis[node] = true;
    for (int it : adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}

string getAlienLanguage(vector<string>& dictionary, int k) {
    vector<vector<int>> adj(k);
    for (int i = 0; i < dictionary.size() - 1; i++) {
        string s1 = dictionary[i];
        string s2 = dictionary[i + 1];
        int len = min(s1.length(), s2.length());
        for (int ptr = 0; ptr < len; ptr++) {
            if (s1[ptr] != s2[ptr]) {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }
    
    vector<bool> vis(k, false);
    stack<int> st;
    for (int i = 0; i < k; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }
    
    string ans = "";
    while (!st.empty()) {
        ans += (char)(st.top() + 'a');
        st.pop();
    }
    return ans;
}
