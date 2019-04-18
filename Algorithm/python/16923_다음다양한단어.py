s = input().strip()
alpa = 'abcdefghijklmnopqrstuvwxyz'
if len(s) == 26:
    r = s[25]
    db = [s[25]]
    ans = s
    for i in range(24,-1,-1):
        for idx in db:
            if s[i] < idx:
                r = idx
                break
        else: 
            db.append(s[i])
            db.sort()
            continue
        ans = s[:i]
        break
    if ans == s:
        print(-1)
    else:
        ans += r
        print(ans)

else:
    for i in range(len(alpa)):
        if alpa[i] not in s:
            s += alpa[i]
            break
    print(s)
