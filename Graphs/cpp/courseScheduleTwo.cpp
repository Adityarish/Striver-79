// Problem Statement: There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

// Problem Link: https://leetcode.com/problems/course-schedule-ii/description/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    if (numCourses == 0) return {};
    vector<int> indegree(numCourses, 0);
    vector<int> order;
    vector<vector<int>> adj(numCourses);
    
    for (auto& pre : prerequisites) {
        indegree[pre[0]]++;
        adj[pre[1]].push_back(pre[0]);
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            order.push_back(i);
            q.push(i);
        }
    }

    while (!q.empty()) {
        int course = q.front();
        q.pop();
        for (int nextCourse : adj[course]) {
            indegree[nextCourse]--;
            if (indegree[nextCourse] == 0) {
                order.push_back(nextCourse);
                q.push(nextCourse);
            }
        }
    }

    return (order.size() == numCourses) ? order : vector<int>();
}
