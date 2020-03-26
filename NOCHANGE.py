for t in range(int(input().rstrip())):
    [N, P] = list(map(int, input().rstrip().split()))
    D = list(map(int, input().rstrip().split()))
    over = []
    for i in range(N):
        if P%D[i] != 0:
            over.append(D[i])
    if len(over) == 0:
        print("NO")
    else:
        over.sort(reverse=True)
        curr = 0
        cnt = 0
        while curr < P:
            curr += over[0]
            cnt += 1
        print("YES", end=" ")
        for i in range(N):
            if D[i] == over[0]:
                print(cnt, end=" ")
            else:
                print(0, end=" ")
        print(flush=True)
