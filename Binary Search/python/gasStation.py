# Problem Statement: You are given a sorted array 'arr' of length 'n', which contains positive integer positions of 'n' gas stations.
# You are also given an integer 'k'. Place 'k' new gas stations on the X-axis.
# Find the minimum value of the maximum distance between adjacent gas stations after adding k new gas stations.

# Problem Link: https://www.codingninjas.com/codestudio/problems/minimise-max-distance_7541449?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


def number_of_gas_stations_required(distance, arr):
    n = len(arr)
    count = 0
    for i in range(1, n):
        number_in_between = int((arr[i] - arr[i - 1]) / distance)
        if (arr[i] - arr[i - 1]) == (distance * number_in_between):
            number_in_between -= 1
        count += number_in_between
    return count


def minimise_max_distance(arr, k):
    n = len(arr)
    low = 0.0
    high = 0.0

    # Find the maximum distance
    for i in range(n - 1):
        high = max(high, float(arr[i + 1] - arr[i]))

    differ = 1e-6
    while high - low > differ:
        mid = (low + high) / 2.0
        count = number_of_gas_stations_required(mid, arr)
        if count > k:
            low = mid
        else:
            high = mid
    return high


if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5]
    k = 4
    ans = minimise_max_distance(arr, k)
    print(f"The answer is: {ans}")
