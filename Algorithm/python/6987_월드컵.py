import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def go(game):
    global ans,looses,wins,draws
    if game == 15:
        ans = True
        return
    if ans:
        return
    a = matchA[game]
    b = matchB[game]
    if wins[a] > 0 and looses[b] > 0:
        wins[a] -= 1; looses[b] -= 1
        go(game+1)
        wins[a] += 1; looses[b] += 1
    if looses[a] > 0 and wins[b] > 0:
        wins[b] -= 1; looses[a] -= 1
        go(game+1)
        wins[b] += 1; looses[a] += 1
    if draws[a] > 0 and draws[b] > 0:
        draws[a] -= 1; draws[b] -= 1
        go(game+1)
        draws[a] += 1; draws[b] += 1

result = []
matchA = [0,0,0,0,0,1,1,1,1,2,2,2,3,3,4]
matchB = [1,2,3,4,5,2,3,4,5,3,4,5,4,5,5]
for _ in range(4):
    ans = False
    wins = []; draws = []; looses = []
    data = list(map(int,input().split()))
    for i in range(6):
        win = data[i*3]; draw = data[i*3 + 1]; loose = data[i*3 + 2]
        if win + draw + loose != 5:
            break
        wins.append(win)
        draws.append(draw)
        looses.append(loose)
    else:
        go(0)
        if ans:
            result.append("1")
            continue
    result.append("0")
print(' '.join(result))