# Problem link: https://www.codingninjas.com/codestudio/problems/majority-element_6915220?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

import math


def majority_element(v):
    n = len(v)  # size of the array

    count1, count2 = 0, 0
    element1, element2 = float('-inf'), float('-inf')

    for i in range(n):
        if count1 == 0 and element2 != v[i]:
            count1 = 1
            element1 = v[i]
        elif count2 == 0 and element1 != v[i]:
            count2 = 1
            element2 = v[i]
        elif v[i] == element1:
            count1 += 1
        elif v[i] == element2:
            count2 += 1
        else:
            count1 -= 1
            count2 -= 1

    result = []  # list of answers

    # Manually check if the stored elements in
    # el1 and el2 are the majority elements:
    count1, count2 = 0, 0
    for i in range(n):
        if v[i] == element1:
            count1 += 1
        if v[i] == element2:
            count2 += 1

    mini = n // 3 + 1
    if count1 >= mini:
        result.append(element1)
    if count2 >= mini:
        result.append(element2)

    result.sort()
    return result


if __name__ == "__main__":
    v = [1, 1, 1, 2, 2, 3]
    ans = majority_element(v)
    print(f"Majority elements (appearing > n/3 times): {ans}")
