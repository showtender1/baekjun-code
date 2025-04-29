n = int(input())

h = 0
for i in range(1, n+1):
    arr = list(map(int, str(i)))
    if i < 100:
        h += 1
    elif arr[0]-arr[1] == arr[1]-arr[2]:
        h += 1
print(h)