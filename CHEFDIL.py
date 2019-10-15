for t in range(int(input())):
    s = list(input())
    i = 0
    c = 0
    while(i<len(s)):
        if s[i] == '1':
            s[i] = '-'
            c += 1
            if i > 0:
                if s[i-1] == '1':
                    s[i-1] = '0'
                elif s[i-1] == '0':
                    s[i-1] = '1'
            if i < len(s)-1:
                if s[i+1] == '1':
                    s[i+1] = '0'
                elif s[i+1] == '0':
                    s[i+1] = '1'
            if i > 0:
                if s[i-1] == '1':
                    i -= 1
                    continue
        i += 1
    if c == len(s):
        print("WIN")
    else:
        print("LOSE")
