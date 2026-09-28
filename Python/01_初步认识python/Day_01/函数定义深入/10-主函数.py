"""
    主函数
·可以区分出其他的结构
·要想实现主函数的定义，就必须借助全局变量‘__name__’的返回值内容而后再采用自定义的函数内容实现
"""
# 观察‘__name__’系统全局变量
def app(h1):
    return lambda h2: h1 + h2
print(__name__)
# open = app(100)
# print(open(30))
"""
此时返回的‘__main__’是一个字符串，但是要注意：以后这个内容是会改变的，因为和结构身处的结构有关
这时就可以在 Python 源代码中通过‘__name__’来进行名称的标注
"""


# 自定义 Python 函数
def hello(h3):
    return lambda h4: h3 + h4
# 主函数的名称是否必须是main()，那么也是由用户来决定的
def main(): # 主函数的特点是不需要有返回值，而且代码的调用要简单
    world = app(100)
    print(world(30))
if(__name__ == "__main__"):
    main()  # 主函数表示一切的起点
