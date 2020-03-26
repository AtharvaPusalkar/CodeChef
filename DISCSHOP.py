t = int(input())
for _ in range(0,t):
    n = input()
    ans = []
    for i in range(0,len(n)):
        print(n[:i], n[i+1:])
        s = n[:i]+n[i+1:]
        ans.append(int(s))
    ans = sorted(ans)
    print(ans[0])