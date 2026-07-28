// Problem Statement: You are given an array/list 'ARR' consisting of 'N' non-negative integers. You are also given a list 'QUERIES' consisting of 'M' queries, where the 'i-th' query is a list/array of two non-negative integers 'Xi', 'Ai', i.e 'QUERIES[i]' = ['Xi', 'Ai'].
// The answer to the ith query, i.e 'QUERIES[i]' is the maximum bitwise xor value of 'Xi' with any integer less than or equal to 'Ai' in 'ARR'. You should return an array/list consisting of 'N' integers where the 'i-th' integer is the answer of 'QUERIES[i]'.

// Problem Link: https://www.codingninjas.com/studio/problems/maximum-xor-with-an-element-from-array_1382020?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    Node* links[2];

    Node() {
        links[0] = links[1] = nullptr;
    }

    bool containsKey(int key) {
        return links[key] != nullptr;
    }

    Node* get(int key) {
        return links[key];
    }

    void put(int key, Node* node) {
        links[key] = node;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getXOR(int num) {
        Node* node = root;
        int maxVal = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxVal = maxVal | (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxVal;
    }
};

vector<int> maxXorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    sort(arr.begin(), arr.end());
    int m = queries.size();
    vector<vector<int>> offlineQueries(m);

    for (int i = 0; i < m; i++) {
        offlineQueries[i] = {queries[i][1], queries[i][0], i};
    }

    sort(offlineQueries.begin(), offlineQueries.end());

    int ind = 0;
    int n = arr.size();
    Trie trie;
    vector<int> ans(m, -1);

    for (int i = 0; i < m; i++) {
        while (ind < n && arr[ind] <= offlineQueries[i][0]) {
            trie.insert(arr[ind]);
            ind++;
        }
        int queryInd = offlineQueries[i][2];
        if (ind != 0) {
            ans[queryInd] = trie.getXOR(offlineQueries[i][1]);
        } else {
            ans[queryInd] = -1;
        }
    }
    return ans;
}
