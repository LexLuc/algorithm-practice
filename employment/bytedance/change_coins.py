# ByteDance Graduation Program, coding test 2
# Date: Spring, 2019
# Author: Lei Luo

# Description:
# You have one banknotes of $1024;
# Type of coins are 64, 16, 4, 1.
# Suppose you buy some goods by $m
# Determin the minimum number of coins of change.

# Input format:
# Integer m indicates $m you spend.

# Output format:
# Integer c indicates minimum number of coins of change.

n = 1024 - int(input())

coins_type = (64, 16, 4, 1)
coins_num = 0

for value in coins_type:
    coins_num += n // value
    n %= value
    if n == 0:
        break

print(coins_num)
