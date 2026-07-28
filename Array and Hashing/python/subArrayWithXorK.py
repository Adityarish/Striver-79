# Problem Statement: Given an array of integers A and an integer B.
# Find the total number of subarrays having bitwise XOR of all elements equal to k.

# Problem Link: https://www.codingninjas.com/codestudio/problems/subarrays-with-xor-k_6826258?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


def subarrays_with_sum_k(a, b):
    n = len(a)  # size of the given array
    xr = 0
    mp = {}     # declaring the map
    mp[xr] = 1  # setting the value of 0
    count = 0

    for i in range(n):
        # prefix xor till index i:
        xr = xr ^ a[i]

        # By formula: x = xr ^ b:
        x = xr ^ b

        # add the occurrence of xr^k to the count:
        if x in mp:
            count += mp[x]

        # Insert the prefix xor till index i into the map:
        mp[xr] = mp.get(xr, 0) + 1

    return count


if __name__ == "__main__":
    a = [4, 2, 2, 6, 4]
    k = 6
    ans = subarrays_with_sum_k(a, k)
    print(f"The number of subarrays with XOR k is: {ans}")
