"""
reduce(func,lst)
其中func必须有两个参数，每次func计算的结果继续和序列的下一个元素做累计计算
注意：
    reduce()传入的参数func必须接受2个参数
需求：
    计算list1序列中各个数字的累加和
"""

list1 = [1, 2, 3, 4, 5]

# 导入模块
import functools


# 定义功能函数
def func(a, b):
    return a + b


# 调用reduce 作用：功能函数计算的结果和序列的下一个数据做累计计算
result = functools.reduce(func, list1)
print(result)
