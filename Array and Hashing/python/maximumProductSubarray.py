# Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

# Problem Link: https://www.codingninjas.com/codestudio/problems/subarray-with-maximum-product_6890008?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


def subarray_with_max_product(arr):
    product1 = arr[0]  # max product ending here
    product2 = arr[0]  # min product ending here
    answer = arr[0]

    # loop for finding maximum product using kadane algorithm
    for i in range(1, len(arr)):
        res = max(arr[i], product1 * arr[i], product2 * arr[i])
        product2 = min(arr[i], product1 * arr[i], product2 * arr[i])
        product1 = res

        answer = max(answer, product1)

    return answer


if __name__ == "__main__":
    nums = [1, 2, -3, 0, -4, -5]
    answer = subarray_with_max_product(nums)
    print(f"The maximum product subarray is: {answer}")
