# Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).
# What is an inversion of an array? Definition: for all i & j < size of array,
# if i < j then you have to find pair (A[i], A[j]) such that A[j] < A[i].

# Problem Link: https://www.codingninjas.com/codestudio/problems/number-of-inversions_6840276?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


def merge_sort(arr, start, end):
    inv_count = 0
    if start >= end:
        return inv_count

    mid = start + (end - start) // 2
    inv_count += merge_sort(arr, start, mid)
    inv_count += merge_sort(arr, mid + 1, end)
    inv_count += merge(arr, start, mid, end)
    return inv_count


def merge(arr, start, mid, end):
    res = []
    i, j = start, mid + 1
    inv_count = 0

    while i <= mid and j <= end:
        if arr[i] <= arr[j]:
            res.append(arr[i])
            i += 1
        else:
            res.append(arr[j])
            j += 1
            # keeping the count of inversions
            inv_count += mid - i + 1

    while i <= mid:
        res.append(arr[i])
        i += 1

    while j <= end:
        res.append(arr[j])
        j += 1

    for k, val in enumerate(res):
        arr[start + k] = val

    return inv_count


def number_of_inversions(a, n):
    return merge_sort(a, 0, n - 1)


if __name__ == "__main__":
    a = [5, 4, 3, 2, 1]
    n = len(a)
    cnt = number_of_inversions(a, n)
    print(f"The number of inversions are: {cnt}")
