# Problem Statement: Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
# However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
# Return the least number of units of times that the CPU will take to finish all the given tasks.

# Problem Link: https://www.codingninjas.com/studio/problems/task-scheduler_1070424?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

from collections import Counter
import heapq

def task_scheduler(s, n, k):
    counts = Counter(s)
    
    # Python's heapq is a min-heap, so we push negative counts for max-heap behavior
    pq = [-count for count in counts.values()]
    heapq.heapify(pq)
    
    result = 0
    while pq:
        time = 0
        tmp = []
        for _ in range(k + 1):
            if pq:
                top = -heapq.heappop(pq)
                if top - 1 > 0:
                    tmp.append(top - 1)
                time += 1
                
        for t in tmp:
            heapq.heappush(pq, -t)
            
        if not pq:
            result += time
        else:
            result += k + 1
            
    return result
