# Problem Statement: There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
# For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
# Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

# Problem Link: https://leetcode.com/problems/course-schedule-ii/description/

from collections import deque

def find_order(num_courses, prerequisites):
    if num_courses == 0:
        return []
        
    indegree = [0] * num_courses
    adj = [[] for _ in range(num_courses)]
    
    for dest, src in prerequisites:
        indegree[dest] += 1
        adj[src].append(dest)

    queue = deque()
    order = []
    
    for i in range(num_courses):
        if indegree[i] == 0:
            order.append(i)
            queue.append(i)

    while queue:
        course = queue.popleft()
        for next_course in adj[course]:
            indegree[next_course] -= 1
            if indegree[next_course] == 0:
                order.append(next_course)
                queue.append(next_course)

    return order if len(order) == num_courses else []
