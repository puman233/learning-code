import math

r = float(input("输入球半径："))
if r <= 0:
    print("error")
    exit()


print(
    "球的半径为：{:.2f}\n".format(4*math.pi*math.pow(r,2)) +
    "球的体积为：{:.2f}\n".format(4*math.pi*math.pow(r,3) / 3)
)
