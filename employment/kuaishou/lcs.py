# Kuaishou Graduation Program, coding test 1
# Date: Spring, 2019
# Author: Lei Luo

# Description:
# Find the length of longest common substring of two strings

# Input Format:
# A pair of strings seperated by comma (,);
# E.g. aabca,ababc

# Output Format:
# The length of lcss
# E.g. 3

def get_length_of_lcss(s1, s2):
    opt = [[0 for j in range(len(s2)+1)] for i in range(len(s1)+1)]
    for i in range(1, len(opt)):
        for j in range(1, len(opt[i])):
            if s1[i-1] != s2[j-1]:
                opt[i][j] = 0
            else:
                opt[i][j] = opt[i-1][j-1] + 1
    return max(max(line) for line in opt)
    
if __name__ == '__main__':
    s1, s2 = input().split(',')
    print(get_length_of_lcss(s1, s2))