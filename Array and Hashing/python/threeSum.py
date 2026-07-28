# Problem Link: https://www.codingninjas.com/codestudio/problems/three-sum_6922132?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


def triplet(n, nums):
    # sort the array
    nums.sort()
    # make a result list
    res = []

    for i in range(len(nums) - 2):
        if i == 0 or (i > 0 and nums[i] != nums[i - 1]):
            low, high = i + 1, len(nums) - 1
            target = -nums[i]
            while low < high:
                if nums[low] + nums[high] == target:
                    res.append([nums[i], nums[low], nums[high]])
                    while low < high and nums[low] == nums[low + 1]:
                        low += 1
                    while low < high and nums[high] == nums[high - 1]:
                        high -= 1
                    low += 1
                    high -= 1
                elif nums[low] + nums[high] < target:
                    low += 1
                else:
                    high -= 1

    return res


if __name__ == "__main__":
    nums = [-1, 0, 1, 2, -1, -4]
    n = len(nums)
    ans = triplet(n, nums)
    print("Triplets that sum to zero:")
    for t in ans:
        print(t)
