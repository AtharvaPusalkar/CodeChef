def solve(a,N): 
      
    res =a[0] 
    curr = a[0] 
      
    for i in range(1,N): 
        curr = max(a[i], curr + a[i]) 
        res = max(res,curr) 
          
    return res

for t in range(int(input().rstrip())):
    N = int(input().rstrip())
    A = list(map(int,input().rstrip().split()))
    print(solve(A,N), end=" ")
    for k in range(N-1):
        A = A[1:]+A[:1]
        print(solve(A,N), end= " ")
    print()
