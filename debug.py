import itertools

x = [0, 1, 'a', 'A']

G0 = []
G1 = []

ans_0 = 0
ans_1 = 0
ans_a = 0
ans_A = 0

combo = [p for p in itertools.product(x, repeat=4)]

a = 0
A = 1

for c in combo.copy():
    curr = ''
    for char in c:
        curr += str(char) + '&'

    curr = curr [:-1] 
    curr.replace('a', str(a))
    curr.replace('A', str(A))
    ans = eval(curr)
    G0.append(ans)

a = 1
A = 0

for c in combo.copy():
    curr = ''
    for char in c:
        curr += str(char) + '&'

    curr = curr [:-1] 
    curr.replace('a', str(a))
    curr.replace('A', str(A))
    ans = eval(curr)
    G1.append(ans)

for i in range(len(G0)):
    if G0[i]==0 and G1[i]==0:
        ans_0 += 1
    elif G0[i]==1 and G1[i]==1:
        ans_1 += 1
    elif G0[i]==0 and G1[i]==1:
        ans_a += 1
    else:
        ans_A += 1

print(f"{ans_0}/{ans_0+ans_1+ans_a+ans_A}", end = " ")
print(f"{ans_1}/{ans_0+ans_1+ans_a+ans_A}", end = " ")
print(f"{ans_a}/{ans_0+ans_1+ans_a+ans_A}", end = " ")
print(f"{ans_A}/{ans_0+ans_1+ans_a+ans_A}", end = " ")
