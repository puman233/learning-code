"""
    所谓全局变量，指的是在函数体内、外都能生效的变量
"""

a = 100
print(a)


def testA():
    print(a)


testA()


def testB():
    print(a)


testB()
