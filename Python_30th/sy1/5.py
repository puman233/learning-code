import math

a = float(input("输入直角边1："))
if a <= 0 :
    print("error")
    exit()

b = float(input("输入直角边2："))
if b <= 0:
    print("error")
    exit()

print("三角形斜边为：{:.2f}".format(math.sqrt(a*a + b*b)))
