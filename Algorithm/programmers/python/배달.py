def solution(N, road, K):
    answer = 1
    inf = 987654321
    d = [[inf] * (N + 1) for i in range(N + 1)]

    # road parsing
    for r in road:
        a, b, c = r[0], r[1], r[2]
        d[a][b] = min(d[a][b], c)
        d[b][a] = min(d[b][a], c)

    # use Floyd-Warshall Algorithm
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            for k in range(1, N + 1):
                d[j][k] = min(d[j][k], d[j][i] + d[i][k])

    # Find the answer
    for i in range(2, N + 1):
        if d[1][i] <= K:
            answer += 1
    return answer