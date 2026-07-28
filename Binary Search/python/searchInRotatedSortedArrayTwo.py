# Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicates)
# and a target value k. The array is rotated at some pivot point. Return true if k is present, otherwise return false.

# Problem Link: https://www.codingninjas.com/codestudio/problems/search-in-a-rotated-sorted-array-ii_7449547?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


def search_in_rotated_sorted_array_ii(a, key):
    # We will be using binary search
    low = 0
    high = len(a) - 1
    while low <= high:
        mid = (low + high) // 2
        # if mid element is key => element found
        if a[mid] == key:
            return True
        # if elements are duplicated
        if a[low] == a[mid] == a[high]:
            low += 1
            high -= 1
            continue
        # find range in which key element is present
        if a[low] <= a[mid]:
            # if element is present in first half => shrink array
            if a[low] <= key <= a[mid]:
                high = mid - 1
            else:
                low = mid + 1
        else:
            if a[mid] <= key <= a[high]:
                low = mid + 1
            else:
                high = mid - 1
    return False


if __name__ == "__main__":
    arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6]
    k = 3
    ans = search_in_rotated_sorted_array_ii(arr, k)
    if not ans:
        print("Target is not present.")
    else:
        print("Target is present in the array.")
