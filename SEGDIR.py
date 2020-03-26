from collections import defaultdict

for _ in range(int(input())):
    speeds_left = defaultdict(list)
    speeds_right = defaultdict(list)
    segs_left = defaultdict(list)
    segs_right = defaultdict(list)

    n = int(input())
    flag = True
    for i in range(n):
        if flag:
            [L, R, V] = list(map(int, input().rstrip().split()))
            if speeds_left[V]:
                cnt = 0
                right = True
                for j in segs_left[V]:
                    if right:
                        if j[0]<=L<=j[1] or j[0]<=R<=j[1] or (L<=j[0] and j[1]<=R):
                            if speeds_right[V]:
                                cnt = 0
                                for k in segs_right[V]:
                                    if k[0]<=L<=k[1] or k[0]<=R<=k[1] or (L<=k[0] and k[1]<=R):
                                        print("NO")
                                        flag = False
                                        right = False
                                        break
                                    cnt += 1
                                if cnt == len(segs_left[V]):
                                    segs_left[V].append([L, R])
                                    right = False
                                    break
                            else:
                                speeds_right[V] = True
                                segs_right[V] = [[L, R],]
                                right = False
                        cnt += 1
                    else:
                        break
                if cnt == len(segs_left[V]):
                    segs_left[V].append([L, R])
            else:
                speeds_left[V] = True
                segs_left[V] = [[L, R],]

    if flag:
        print("YES")