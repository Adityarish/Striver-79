# Problem Statement: A monkey is given 'n' piles of bananas, where the 'ith' pile has 'a[i]' bananas.
# An integer 'h' is also given, which denotes the time (in hours) for all the bananas to be eaten.
# Find the minimum number of bananas 'k' to eat per hour so that the monkey can eat all the bananas within 'h' hours.

# Problem Link: https://www.codingninjas.com/codestudio/problems/minimum-rate-to-eat-bananas_7449064?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

import math


def total_hours(v, hours):
    return sum(math.ceil(bananas / hours) for bananas in v)


def minimum_rate_to_eat_bananas(v, h):
    low = 1
    high = max(v)
    while low <= high:
        mid = (low + high) // 2
        total = total_hours(v, mid)
        if total <= h:  # min can be found in left part
            high = mid - 1
        else:
            low = mid + 1  # min can be found in right part
    return low


if __name__ == "__main__":
    v = [7, 15, 6, 3]
    h = 8
    ans = minimum_rate_to_eat_bananas(v, h)
    print(f"Koko should eat at least {ans} bananas/hr.")
