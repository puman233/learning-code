"""
filter(func,lst)
用于过滤序列，过滤掉不符合条件的元素，返回一个filter对象
可用list()转换列表
"""

list1 = [1, 2, 3, 4, 5]


def func(x):
    return x % 2 == 0


result = filter(func, list1)
print(list(result))
