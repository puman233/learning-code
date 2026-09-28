"""
    lambda 表达式
·lambda 被称为 lambda 函数，lambda 指的是函数式编程
·函数式编程就是没有名字的函数，所以这样的函数一般定义比较简单，并且只使用一次
·语法：
    ·lambda 参数，参数，参数，…… + 程序语句
·注意：千万不要在 lambda 函数里编写特别多的语句，一般是单行解决就行了
"""
# 定义 lambda 函数
# sum 是一个函数应用的标记名称
sum = lambda x,y,z: x + y + z   # 定义 lambda 函数
print(sum(30,39,49))


# 使用 lambda 函数实现闭包操作
def app(h1):
    return lambda h2 : h2 + h1
hello = app(100)
print(hello(50))