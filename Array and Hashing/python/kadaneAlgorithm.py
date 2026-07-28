# Problem link: https://bit.ly/3HZltTa


def max_subarray_sum(arr, n):
    if n == 0 or arr is None:
        return 0

    meh = 0
    # maximum sum so far
    msf = float('-inf')

    for i in range(n):
        meh = meh + arr[i]
        if meh < arr[i]:
            meh = arr[i]
        if meh > msf:
            msf = meh
        # if maximum sum so far becomes negative at
        # any point we just initialize it as zero
        if msf < 0:
            msf = 0

    # return maximum sum
    return msf


if __name__ == "__main__":
    arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    n = len(arr)
    print(f"The maximum subarray sum is: {max_subarray_sum(arr, n)}")
