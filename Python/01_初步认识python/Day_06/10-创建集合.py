"""
    · 创建集合用{}或set()，但是如果要创建空集合只能用set()，因为{}用来创建空字典
"""

# 创建有数据的集合
s1 = {10,20,30}
print(s1)
print(type(s1))

s2 = {10,20,30,40,50,60}
print(s2)
print(type(s2))

s3 = set('abcdefg')
print(s3)

# 创建空集合
s4 = set()
print(s4)
print(type(s4))
