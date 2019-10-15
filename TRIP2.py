for t in range(int(input())):
    NK = list(map(int, input().rstrip().split()))
    N = NK[0]
    K = NK[1]
    A = list(map(int, input().rstrip().split()))
    P = list(range(1, K+1))
    flag = True
    for i in range(len(A)):
        if flag:
            if A[i] == -1:
                for j in range(0, K):
                    if i == len(A)-1:
                        if j == K - 1 and A[i-1] != P[j]:
                            print("NO")
                            flag = False
                            break
                        if P[j] != A[i-1]:
                            A[i] = P[j]
                            break
                    if j == K - 1 and (A[i-1] == P[j] or A[i+1] == P[j]):
                        print("NO")
                        flag = False
                        break
                    if P[j] != A[i-1] and P[j] != A[i+1]:
                        A[i] = P[j]
                        break
    if flag:
        print("YES")
        print(*A)
                    
                
                     