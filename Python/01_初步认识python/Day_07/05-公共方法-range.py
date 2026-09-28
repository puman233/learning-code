"""
    range(start,end,step)   生成从start到end的数字，步长为step，供for循环使用
"""

# print(range(1,10,1))

for i in range(1,10,1):
    print(i)

print('-' * 10 + "分割线" + '-' * 10)


# 省略步长
for a in range(1,10):
    print(a)


print('-' * 10 + "分割线" + '-' * 10)


# 省略开始和补偿。其中省略开始时，默认从0开始
# 切记：不能省略结束
for c in range(10):
    print(c)
