import sys
input = sys.stdin.readline

N = int(input())
P = list(map(int, input().split()))
S = list(map(int, input().split()))

cards = [i for i in range(N)]

def shuffle():
    global cards

    t = [-1] * N
    for i in range(N):
        t[S[i]] = cards[i]
    cards = t

def check():
    for i in range(N):
        x = cards[i]
        if P[x] != i%3:
            return False
    return True

def convert():
    v = 0
    for i in range(N):
        v += 10**i * cards[i]
    return v

dd = {}

cnt = 0
while check() == False:
    k = convert()
    if dd.get(k) == None:
        dd[k] = 1
    else:
        cnt = -1
        break

    cnt += 1
    shuffle()
    
print(cnt)