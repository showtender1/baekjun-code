n = int(input())

m = [str(input()) for i in range(n)]

m = list(set(m))
m.sort()
m.sort(key=len)

for i in m:
    print(i)