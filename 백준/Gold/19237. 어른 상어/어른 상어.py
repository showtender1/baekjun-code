n, m, k = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
d = list(map(int, input().split()))
shark = [[] for _ in range(m)]
first = [[] for _ in range(m)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(m):
    for _ in range(4):
        first[i].append(list(map(int, input().split())))

for i in range(n):
    for j in range(n):
        if arr[i][j] != 0:
            shark[arr[i][j] - 1] = [i, j, d[arr[i][j] - 1] - 1]
        arr[i][j] = [0, 0]

def smell(arr, shark):
    for i in range(len(shark)):
        if shark[i]:
            x, y, d = shark[i]
            arr[x][y] = [k, i]
    return arr

def next(arr):
    for i in range(n):
        for j in range(n):
            if arr[i][j][0] > 0:
                arr[i][j][0] -= 1
    return arr

def move(shark):
    tmp = [[[] for _ in range(n)] for _ in range(n)]
    for i in range(len(shark)):
        if shark[i]:
            x, y, d = shark[i]
            left = []
            mleft = []
            for k in range(4):
                nx, ny = x + dx[k], y + dy[k]
                if 0 <= nx < n and 0 <= ny < n:
                    if arr[nx][ny][0] == 0:
                        left.append((nx, ny, k))
                    elif arr[nx][ny][1] == i:
                        mleft.append((nx, ny, k))
            if not left:
                left = mleft
            if left:
                rank = first[i][d]
                for r in rank:
                    for a, b, c in left:
                        if r - 1 == c:
                            nd = r - 1
                            shark[i] = [a, b, nd]
                            tmp[a][b].append(i)
                            break
                    else:
                        continue
                    break

    for i in range(n):
        for j in range(n):
            if len(tmp[i][j]) > 1:
                tmp[i][j].sort()
                for k in tmp[i][j][1:]:
                    shark[k] = []

    cnt = 0
    for i in range(m):
        if shark[i]:
            cnt += 1
    return shark, cnt

for i in range(1000):
    arr = smell(arr, shark)
    shark, live = move(shark)
    arr = next(arr)
    if live == 1:
        print(i + 1)
        break
else:
    print(-1)
