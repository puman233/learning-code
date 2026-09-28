# x²-10x+16=0

import math

a = 1
b = -10
c = 16
delta = math.pow(b, 2) - 4 * a * c

x1 = (-b + math.sqrt(delta)) / (2 * a)
x2 = (-b - math.sqrt(delta)) / (2 * a)

print(
    "1解：{}\n".format(x1) + 
    "2解：{}".format(x2)
)
