import numpy as np

for t in range(int(input())):
    n = int(input())
    C = np.array(list(map(int, input().rstrip().split())))
    Z = np.array(list(map(int, input().rstrip().split())))
    L = np.zeros(n)
    for i in range(n):
        lo = max(0, i-C[i])
        hi = min(n-1, i+C[i])
        for j in range(lo, hi+1):
            L[j] += 1
    L = np.sort(L)
    Z = np.sort(Z)
    count = 0
    for i in range(n):
        if Z[i] == L[i]:
            count += 1
    if count == n:
        print("YES")
    else:
        print("NO")