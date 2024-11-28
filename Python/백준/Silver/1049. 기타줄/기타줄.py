n, m = map(int, input().split())
package = []
single = []

for _ in range(m):
    a, b = map(int, input().split())
    package.append(a)
    single.append(b)

ans = 0
min_package = min(package)
min_single = min(single)

while n > 0:
    if n >= 6:
        ans += min(min_package, min_single * 6)
        n -= 6
    else:
        ans += min(min_package, min_single * n)
        break
print(ans)
