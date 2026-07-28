# Problem Statement: You are given a string consisting of open and close brackets. Your task is to determine the minimum cost required to make the string valid.
# A string is considered valid if and only if:
# It is non-empty.
# Each open bracket '{' must have a corresponding close bracket '}'.
# The brackets must be in pairs and properly nested. For example, '{}' and '{{}}' are valid, but '{', '}{', and '{}}' are not valid.

# Problem Link: https://www.codingninjas.com/studio/problems/minimum-cost-to-make-string-valid_1115770?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def find_minimum_cost(str_val):
    if len(str_val) % 2 != 0:
        return -1
        
    s = []
    for ch in str_val:
        if ch == '{':
            s.append(ch)
        else:
            if s and s[-1] == '{':
                s.pop()
            else:
                s.append(ch)
                
    open_count = 0
    close_count = 0
    
    while s:
        if s[-1] == '{':
            open_count += 1
        else:
            close_count += 1
        s.pop()
        
    cost = (open_count + 1) // 2 + (close_count + 1) // 2
    return cost
