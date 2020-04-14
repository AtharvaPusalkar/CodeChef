import itertools

MOD = 998244353

def pow_mod(b, p):
    ans=1
    global MOD
    while p:
        if p&1:
            ans = ans * b%MOD
        b = b*b%MOD
        p = p//2
    return ans

exp = '((#&#)&(#&#))'

p = ['((', ')', '(', '))']

x = ['0', '1', 'a', 'A']

G0 = []
G1 = []

ans_0 = 0
ans_1 = 0
ans_a = 0
ans_A = 0

p_ind = 0

combo = [p for p in itertools.product(x, repeat=4)]

for c in combo:
    # exp = '(('+c[0]+'|'+c[1]+')'+'|'+'('+c[2]+'^'+c[3]+'))'
    # exp = '(((' + c[0] + '&' + c[1] + ')&' + c[2] + ')|' + '(' +c[3] + '|' + c[4] + '))'
    # exp = '(((' + c[0] + '|' + c[1] + ')|' + c[2] + ')|' + c[3] + ')'
    exp = '((' + c[0] + '&' + c[1] + ')' + '|' + '(' + c[2] + '&' + c[3] +'))'
    # exp = '((' + c[0] + '&' + c[1] + ')' + '&' + c[2] + ')' 

    a, A = 0, 1
    ans_g0 = eval(exp)

    a, A = 1, 0
    ans_g1 = eval(exp) 

    if ans_g0==0 and ans_g1==0:
        ans_0 += 1
        # print(exp)
    elif ans_g0==1 and ans_g1==1:
        ans_1 += 1
        #print(exp)
    elif ans_g0==0 and ans_g1==1:
        ans_a += 1
    else:
        ans_A += 1

print(f"{ans_0}", end = " ")
print(f"{ans_1}", end = " ")
print(f"{ans_a}", end = " ")
print(f"{ans_A}", end = " ")

print()

print(f"{ (ans_0%MOD *pow_mod(ans_0+ans_1+ans_a+ans_A, MOD-2))%MOD}", end = " ")
print(f"{ (ans_1%MOD *pow_mod(ans_0+ans_1+ans_a+ans_A, MOD-2))%MOD}", end = " ")
print(f"{ (ans_a%MOD *pow_mod(ans_0+ans_1+ans_a+ans_A, MOD-2))%MOD}", end = " ")
print(f"{ (ans_A%MOD *pow_mod(ans_0+ans_1+ans_a+ans_A, MOD-2))%MOD}", end = " ")

# for i in range(len(G0)):
#     print(f"{G0[i]} {G1[i]}")