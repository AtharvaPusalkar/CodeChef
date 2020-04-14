# 0.87 pts in DIV 1

import numpy as np

def min_indices(row):
    m  = np.amin(row)
    indices = np.where(row==m)[0]
    return indices

def choice(row, indices):
    arr = sorted([row[i] for i in indices])
    # for i in indices:
    #     arr.append(row[i])

    count = 1
    val = arr[0]
    curr = 1

    for i in range(1, len(arr)):
        if arr[i] == arr[i-1]:
            curr += 1
        else:
            if curr > count:
                count = curr
                val = arr[i-1]
            curr = 1
    
    if curr > count:
        val = arr[len(arr)-1]

    return val

for _ in range(int(input())):
    N,M,K = list(map(int,input().rstrip().split()))
    c = np.empty((N,K), dtype=np.int32)
    for i in range(N):
        row = list(map(int,input().rstrip().split()))
        for j in range(len(row)):
            c[i][j] = row[j]
    answers = []
    
    cost = np.zeros(K, dtype=np.int32)
    ind = min_indices(cost)
    answers.append(choice(c[0], ind))

    for i in range(K):
        if c[0][i] == answers[len(answers)-1]:
            cost[i] += 1

    # print(f"curr choice = {answers[len(answers)-1]}, cost = {cost}")

    for i in range(1,N):
        ind = min_indices(cost)
        answers.append(choice(c[i], ind))

        for j in range(K):
            if c[i][j] == answers[len(answers)-1]:
                cost[j] += 1

        # print(f"curr choice = {answers[len(answers)-1]}, cost = {cost}")

    print(*answers)