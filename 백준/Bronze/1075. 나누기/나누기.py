num = input()
n = int(input())
num = int(num[:-2] + '00')
while True:
    if num % n == 0:
        break
    num += 1
print(str(num)[-2:])