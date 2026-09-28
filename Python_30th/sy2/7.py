n = int(input("输入打印行数："))

for i in range(1, n):
    if i == 1:
        print("*")
    elif i == 2:
        print("**")
    elif i > 2 and i < n:
        print("*" + " " * (i - 2) + "*")
print("*" * n)
