def slope(x1, y1, x2, y2):
    return (y2 - y1) / (x2 - x1)

n = int(input())
arr = list(map(int, input().split()))

res = 0
for i1, y1 in enumerate(arr):
    x1 = i1 + 1
    # 오른쪽으로 보이는 점 세기
    curr = None
    vr = 0
    for i2 in range(i1 + 1, n):
        x2 = i2 + 1
        y2 = arr[i2]
        sr = slope(x1, y1, x2, y2)
        if curr is None or sr > curr:
            curr = sr
            vr += 1

    curl = None
    vl = 0
    for i3 in range(i1 - 1, -1, -1):
        x2 = i3 + 1
        y2 = arr[i3]
        sl = slope(x1, y1, x2, y2)
        if curl is None or sl < curl:
            curl = sl
            vl += 1

    if vr + vl > res:
        res = vr + vl

print(res)
