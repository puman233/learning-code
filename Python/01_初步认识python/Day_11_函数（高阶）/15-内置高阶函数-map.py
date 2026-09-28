"""
map(func,lst)
将传入的函数变量func作用到lst变量的每个元素中，并将结果组成新的列表
"""

# 需求：计算list1序列中各个数字的2次方

# 1.准备
list1 = [1, 2, 3, 4, 5]


# 2.准备2次方计算的函数
def func(x):
    return x ** 2


# 3.调用map
result = map(func, list1)
print(result)
print(list(result))
