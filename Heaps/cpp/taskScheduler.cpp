// Problem Statement: Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
// However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
// Return the least number of units of times that the CPU will take to finish all the given tasks.

// Problem Link: https://www.codingninjas.com/studio/problems/task-scheduler_1070424?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

int taskScheduler(string s, int n, int k) {
    unordered_map<char, int> counts;
    for (char t : s) {
        counts[t]++;
    }

    priority_queue<int> pq;
    for (auto& it : counts) {
        pq.push(it.second);
    }

    int result = 0;
    while (!pq.empty()) {
        int time = 0;
        vector<int> tmp;
        for (int i = 0; i < k + 1; ++i) {
            if (!pq.empty()) {
                int top = pq.top();
                pq.pop();
                if (top - 1 > 0) {
                    tmp.push_back(top - 1);
                }
                time++;
            }
        }
        for (int t : tmp) {
            pq.push(t);
        }
        result += pq.empty() ? time : k + 1;
    }
    return result;
}
