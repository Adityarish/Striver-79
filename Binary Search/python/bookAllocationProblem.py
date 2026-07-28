# Problem Statement: Given an array 'arr' of integer numbers, 'arr[i]' represents the number of pages in the 'i-th' book.
# There are 'm' number of students, and the task is to allocate all the books to the students.
# Each student gets at least one book. Each book should be allocated to only one student.
# Book allocation should be in a contiguous manner.
# Allocate books such that the maximum number of pages assigned to a student is minimum.
# If the allocation of books is not possible, return -1.

# Problem Link: https://www.codingninjas.com/codestudio/problems/allocate-books_1090540?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


def count_students(arr, pages):
    students = 1
    pages_student = 0
    for page in arr:
        if pages_student + page <= pages:
            # add pages to current student
            pages_student += page
        else:
            # add pages to next student
            students += 1
            pages_student = page
    return students


def find_pages(arr, n, m):
    # if number of students is greater than number of books
    if m > n:
        return -1
    # low = maximum in array, high = sum of all elements
    low = max(arr)
    high = sum(arr)
    while low <= high:
        mid = (low + high) // 2
        students = count_students(arr, mid)
        if students > m:
            # right part
            low = mid + 1
        else:
            # left part
            high = mid - 1
    return low


if __name__ == "__main__":
    arr = [25, 46, 28, 49, 24]
    n = 5
    m = 4
    ans = find_pages(arr, n, m)
    print(f"The answer is: {ans}")
