import sys
t = int(sys.stdin.readline())
for _ in range(t):
    m = int(sys.stdin.readline())
    l = list(map(int, sys.stdin.readline().split()))
    r = list(map(int, sys.stdin.readline().split()))
    c = 0
    i = 0
    while i < m:
        if l[i] < r[i]:
            c += 1
        i += 2
    print(c)
