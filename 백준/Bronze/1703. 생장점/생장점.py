while 1:
    arr = list(map(int, input().split()))
    if arr[0] == 0:
        break
    n = 1
    for i in range(arr[0]):
        m = arr[2*i + 1]
        p = arr[2*i + 2]
        n = n * m - p
    print(n)