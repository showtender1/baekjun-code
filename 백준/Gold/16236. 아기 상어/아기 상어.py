from collections import deque
def yammy(a, b, n, fish, shark):
    dist = [[0] * n for _ in range(n)]
    visit = [[0] * n for _ in range(n)]
    queue = deque()
    queue.append([a, b])
    visit[a][b] = 1
    candidates = []
    while queue:
        y, x = queue.popleft()
        for dy, dx in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
            ny, nx = y + dy, x + dx
            if 0 <= ny < n and 0 <= nx < n and visit[ny][nx] == 0:
                if shark >= fish[ny][nx]:
                    visit[ny][nx] = 1
                    dist[ny][nx] = dist[y][x] + 1
                    queue.append([ny, nx])
                    if fish[ny][nx] and shark > fish[ny][nx]:
                        candidates.append([ny, nx, dist[ny][nx]])

    return sorted(candidates, key=lambda x: (x[2], x[0], x[1]))
n = int(input())
fish = [list(map(int, input().split())) for _ in range(n)]
y, x = 0, 0
shark, result = 2, 0

for i in range(n):
    for j in range(n):
        if fish[i][j] == 9:
            y, x = i, j
            fish[i][j] = 0
eat = 0
while True:
    candidates = yammy(y, x, n, fish, shark)
    if not candidates:
        break
    cy, cx, time = candidates.pop(0)
    result += time
    fish[cy][cx] = 0
    y, x = cy, cx
    eat += 1
    if eat == shark:
        shark += 1
        eat = 0
print(result)
