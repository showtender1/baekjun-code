n = int(input())

found = False

for a in range(2, 10):
    for b in range(1, 10):
        if n == a or n == b or n == a * b:
            found = True
            break
    if found:
        break

print(1 if found else 0)
