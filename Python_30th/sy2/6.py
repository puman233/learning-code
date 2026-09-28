n = int(input())
res = 1
for i in range(n, 0, -1):
    res *= i

print(res)

res = 1
while n > 0:
    res *= n
    n -= 1
print(res)