# Problem Link: https://www.codingninjas.com/codestudio/problems/next-greater-permutation_6929564?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


def next_greater_permutation(A):
    n = len(A)  # size of the array

    # Step 1: Find the break point:
    ind = -1  # break point
    for i in range(n - 2, -1, -1):
        if A[i] < A[i + 1]:
            # index i is the break point
            ind = i
            break

    # If break point does not exist:
    if ind == -1:
        # reverse the whole array:
        A.reverse()
        return A

    # Step 2: Find the next greater element
    #         and swap it with A[ind]:
    for i in range(n - 1, ind, -1):
        if A[i] > A[ind]:
            A[i], A[ind] = A[ind], A[i]
            break

    # Step 3: reverse the right half:
    A[ind + 1:] = A[ind + 1:][::-1]

    return A


if __name__ == "__main__":
    A = [1, 3, 2]
    ans = next_greater_permutation(A)
    print(f"The next permutation is: {ans}")
