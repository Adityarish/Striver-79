# Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive.
# Each integer appears exactly once except A which appears twice and B which is missing.
# The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

# Problem Link: https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_6828164?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


def find_missing_repeating_numbers(arr):
    n = len(arr)

    # Find Sn and S2n:
    SN = (n * (n + 1)) // 2
    S2N = (n * (n + 1) * (2 * n + 1)) // 6

    # Calculate S and S2:
    S = sum(arr)
    S2 = sum(x * x for x in arr)

    val1 = S - SN       # repeating - missing
    val2 = S2 - S2N     # repeating^2 - missing^2

    val2 = val2 // val1  # repeating + missing

    a = (val1 + val2) // 2   # repeating number
    b = a - val1              # missing number

    return [a, b]


if __name__ == "__main__":
    a = [3, 1, 2, 5, 4, 6, 7, 5]
    ans = find_missing_repeating_numbers(a)
    print(f"The repeating and missing numbers are: {{{ans[0]}, {ans[1]}}}")
