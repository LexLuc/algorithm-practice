# ByteDance Graduation Program, coding test 3
# Date: Spring, 2019
# Author: Lei Luo

# Description:
# N people won the competetion and waiting for awarding.
# Each person have its own score.
# Now they are standing in a circle.
# The rule of awarding prizes is:
# One should be awarded more prizes 
# if his / her neighbour has lower score than he / she does.
# You need to determine the minimum number of prizes that does obey the rule.

# Input format:
# integer M indicates M test cases
# followed by each case of integer N and N scores of people

# Output format:
# M lines of prizes number each person deserves.

n_cases = int(input())

cases = [(int(input()), [int(score) for score in input().split()])
        for _ in range(n_cases)]

for case in cases:
    n, scores = case
    prizes = [0 for _ in range(n)]
    sorted_scores_idx = sorted(range(len(scores)), key=scores.__getitem__)

    last_score = sorted_scores_idx[0]
    least_prize = 1

    for idx in sorted_scores_idx:
        prizes[idx] = max(least_prize, prizes[idx])
        if scores[idx] < scores[idx -1]:
            prizes[idx -1] = max(prizes[idx] +1, prizes[idx -1])
        if scores[idx] < scores[(idx +1) % n]:
            prizes[(idx +1) % n] = max(prizes[idx] +1, prizes[(idx +1) % n])

    print(prizes)
