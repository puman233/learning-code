"""
    callable 函数
·前言：
    ·内置对象函数本质上就是内置函数，和‘input()’、‘len()’是类似的
     但是与之称之为对象函数是因为在使用的过程之中较为特殊
    ·在 Python 中提供的内置函数的额定义是相当多的，主要是为了方便开发者进行项目开发
·功能：
    ·给判定的结构是否可以被调用
    ·对于一些变量如果是可以调用的结构，就可以通过此函数做出哦按段，返回布尔型数据
"""
# 观察 callable 函数
print("input()函数是否可以调用：%s" % callable(input))
print("'hello'字符串是否可以调用：%s" % callable("hello"))
def get_info():
    return "https://www.csdn.com"
open_book = get_info    # 函数引用
print("get_info()函数是否可以调用：%s" % callable(get_info))
print("open_book引用对象是否可以调用：%s" % callable(open_book))

