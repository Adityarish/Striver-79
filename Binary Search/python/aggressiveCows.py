# Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls.
# You are also given an integer 'k' which denotes the number of aggressive cows.
# You are given the task of assigning stalls to 'k' cows such that the minimum distance between
# any two of them is the maximum possible. Find the maximum possible minimum distance.

# Problem Link: https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


def can_we_place(arr, distance, cows):
    # we assume we already placed one cow
    count_cows = 1
    # position where last cow was placed
    last_cow = arr[0]
    for i in range(1, len(arr)):
        if arr[i] - last_cow >= distance:
            # increase count of cow
            count_cows += 1
            # position of ith cow
            last_cow = arr[i]
        # if we placed all desired cows we can return true
        if count_cows >= cows:
            return True
    return False


def aggressive_cow(stalls, k):
    # sort the array
    stalls.sort()
    low = 0
    high = stalls[-1] - stalls[0]
    while low <= high:
        mid = (low + high) // 2
        if can_we_place(stalls, mid, k):
            # if it is possible to place cow at mid, go right
            # because we want maximum and we will get max on right
            low = mid + 1
        else:
            high = mid - 1
    # high will be at maximum distance we can get
    return high


if __name__ == "__main__":
    stalls = [0, 3, 4, 7, 10, 9]
    k = 4
    ans = aggressive_cow(stalls, k)
    print(f"The maximum possible minimum distance is: {ans}")
