for t in range(int(input().rstrip())):
    N = int(input().rstrip())
    temp = 10**N
    S = 2*temp
    A = int(input().rstrip())
    S += A
    print(S, flush=True)
    B = int(input().rstrip())
    C = temp-B
    print(C, flush=True)
    D = int(input().rstrip())
    E = temp-D
    print(E, flush=True)
    flag = int(input().rstrip())
    if flag == -1:
        break
