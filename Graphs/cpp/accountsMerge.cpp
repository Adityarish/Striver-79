// Problem Statement: Given a list of accounts where each element account [ i ] is a list of strings, where the first element account [ i ][ 0 ]  is a name, and the rest of the elements are emails representing emails of the account.
// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order.

// Note: Accounts themselves can be returned in any order.

// Problem Link: https://www.codingninjas.com/studio/problems/accounts-merge_1089558?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    DisjointSet ds(n);

    unordered_map<string, int> emailToIndex;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
            string email = accounts[i][j];
            if (emailToIndex.find(email) == emailToIndex.end()) {
                emailToIndex[email] = i;
            } else {
                ds.unionByRank(i, emailToIndex[email]);
            }
        }
    }

    unordered_map<int, vector<string>> mergedEmails;

    for (auto it : emailToIndex) {
        string email = it.first;
        int node = ds.findParent(it.second);
        mergedEmails[node].push_back(email);
    }

    vector<vector<string>> result;

    for (int i = 0; i < n; i++) {
        if (mergedEmails.find(i) != mergedEmails.end()) {
            vector<string> mergedList = mergedEmails[i];
            sort(mergedList.begin(), mergedList.end());
            mergedList.insert(mergedList.begin(), accounts[i][0]);
            result.push_back(mergedList);
        }
    }

    return result;
}
