# Kuaishou Graduation Program, coding test 2
# Date: Spring, 2019
# Author: Lei Luo

# Description:
# Find the missing value from an array of length N
# which contains distinct numbers from 0 to N,
# i.e. there must be a missing value.

# Input Format:
# A line of numbers seperated by comma (,);
# E.g. 3,1,2,6,4,7

# Output Format:
# The missing value.
# E.g. 5

# Time: O(2N), Space: O(2N)
def get_missing_val_by_count_sort(arr):
    count_arr = [0 for _ in range(len(arr)+1)]
    for e in arr:
        count_arr[e] += 1
    for i in range(len(count_arr)):
        if count_arr[i] == 0:
            return i

# Time: O(N), Space: O(N)
def get_missing_val_by_substraction(arr):
    n = len(arr) + 1
    sum_of_complete_arr = (n*(n-1)) // 2
    sum_of_missing_arr = sum(arr)
    return sum_of_complete_arr - sum_of_missing_arr

if __name__ == '__main__':
    arr = [int(ch) for ch in input().split(',')]
    print(get_missing_val_by_count_sort(arr))
    print(get_missing_val_by_substraction(arr))