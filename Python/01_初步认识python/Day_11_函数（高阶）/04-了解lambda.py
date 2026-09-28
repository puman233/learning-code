"""
如果一个函数有一个返回值，并且只有一句代码
可以使用lambda简化

语法：
    lambda 参数列表 :　表达式

注意：
    lambda表达式的参数可有可无，函数的参数在lambda表达式完全适用
    lambda表达式能够接受任何数量的参数但只能返回一个表达式的值
"""


# 体验lambda

# 函数
def fn1():
    return 100


result = fn1()
print(result)

# lambda
fn2 = lambda: 100
print(fn2)

# 100的返回值
print(fn2())

