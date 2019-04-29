# Date: Spring, 2019
# Author: Lei Luo

# Description:
# Check & correct if there were some typos in a string,
# where typos are defined as follows:
# Three same characters appears together, e.g. "AAA" -> "AA"
# Two same couple of characters appears together, e.g. "ABAB" -> "ABA"
# Typos are left associative, e.g. "AABBB" -> "AABB" -> "AAB"

# Input format:
# An integer N indicates next N lines;
# Consecutive N lines of strings to be corrected.

# Output format:
# N lines of corrected string.

n = int(input())

lines = [input() for _ in range(n)]

def check_three_same_ch(string):
    for i in range(len(string) -2):
        if string[i] == string[i+1] == string[i+2]:
            return i
    return None

def check_two_couple(string):
    for i in range(len(string) -3):
        if string[i] == string[i+1] and string[i+2] == string[i+3]:
            return i+3
    return None

def correct_string(string, i):
    return string[:i] + string[i+1:]

corrected_lines = []
for line in lines:
    if len(line) < 3:
        corrected_line = line
    elif len(line) == 3:
        idx_to_del = check_three_same_ch(line)
        if idx_to_del is not None:
            corrected_line = correct_string(line, idx_to_del)
        else:
            corrected_line = line
    else:
        corrected_line = line
        while True:
            idx_to_del_3 = check_three_same_ch(corrected_line)
            if idx_to_del_3 is not None:
                corrected_line = correct_string(corrected_line, idx_to_del_3)

            idx_to_del_2 = check_two_couple(corrected_line)
            if idx_to_del_2 is not None:
                corrected_line = correct_string(corrected_line, idx_to_del_2)
            
            if idx_to_del_2 is None and idx_to_del_3 is None:
                break

    corrected_lines.append(corrected_line)

for line in corrected_lines:
    print(line)