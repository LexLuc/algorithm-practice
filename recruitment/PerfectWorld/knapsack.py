# Perfect World Graduation Program, coding test 1
# Date: Spring, 2019
# Author: Lei Luo

# Description:
# 0-1 Knapsack Problem

# Input format:
# n -- number of items to put into the knapsack;
# values -- a line of n positive integers of values for each item;
# weights -- another line of n positive integers of weights for each item;
# capacity -- total weights the knapsack can hold.

# Output format:
# An integer representing the maximum values of items to take.

def knapsack(values, weights, capacity):
    assert len(values) == len(weights)
    opt = [[0 for j in range(capacity+1)] for i in range(len(values)+1)]
    for i in range(1, len(values)+1):
        for j in range(1, capacity+1):
            if j < weights[i-1]:
                opt[i][j] = opt[i-1][j]
            else:
                opt[i][j] = max(opt[i-1][j], values[i-1]+opt[i-1][j-weights[i-1]])
    return opt[-1][-1]

if __name__ == '__main__':
    n = int(input())
    values = [int(e) for e in input().split()]
    weights = [int(e) for e in input().split()]
    capacity = int(input())
    print(knapsack(values, weights, capacity))