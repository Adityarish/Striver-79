# Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively,
# return the median of the two sorted arrays.
# The median is defined as the middle value of a sorted list of numbers.
# In case the length of the list is even, the median is the average of the two middle elements.

# Problem Link: https://www.codingninjas.com/codestudio/problems/median-of-two-sorted-arrays_985294?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

import math


def median(a, b):
    n1 = len(a)
    n2 = len(b)

    # if n1 is bigger, swap the arrays
    if n1 > n2:
        return median(b, a)

    n = n1 + n2  # total length
    left = (n1 + n2 + 1) // 2  # length of left half

    # apply binary search
    low, high = 0, n1

    while low <= high:
        mid1 = (low + high) // 2
        mid2 = left - mid1

        # calculate l1, l2, r1 and r2
        l1 = a[mid1 - 1] if mid1 > 0 else -math.inf
        l2 = b[mid2 - 1] if mid2 > 0 else -math.inf
        r1 = a[mid1] if mid1 < n1 else math.inf
        r2 = b[mid2] if mid2 < n2 else math.inf

        if l1 <= r2 and l2 <= r1:
            if n % 2 == 1:
                return max(l1, l2)
            else:
                return (max(l1, l2) + min(r1, r2)) / 2.0
        elif l1 > r2:
            high = mid1 - 1
        else:
            low = mid1 + 1
    return 0


if __name__ == "__main__":
    a = [1, 4, 7, 10, 12]
    b = [2, 3, 6, 15]
    print(f"The median of two sorted arrays is {median(a, b)}")
