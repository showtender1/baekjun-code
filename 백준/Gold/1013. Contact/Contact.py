import re
import sys

t = int(sys.stdin.readline())
res = []

for _ in range(t):
    sign = sys.stdin.readline().replace('\n', '')
    p = re.compile('(100+1+|01)+')
    m = p.fullmatch(sign)
    if m: res.append("YES")
    else: res.append("NO")

for res in res:
    sys.stdout.write(str(res)+'\n')