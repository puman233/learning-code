"""
    函数
·意义：向结构化的可重用程序开发迈进
·例如：Python内置函数：print(),len()等等
·除了内置函数，用户也可以自定义函数
·语法：
    def 函数名称([参数,参数,...]):
    函数主题代码(多行代码)
    (return[返回值])
        ·在函数定义之后是否有返回值，由 return 来决定
"""
# 定义一个无参数由返回值的函数
def hello():        # 命名要遵循标识符要求
    """
        定义一个信息获取的功能函数操作
    :return:返回给调用处显示的内容
    """
    return "hello world"
print(hello()) # 调用函数，直接进行返回内容的输出
world = hello() # 进行返回值的接收
print(world) # 进行返回值的输出
# Python中函数实际上也属于一个结构体，那么这个结构体可以直接进行类型获取
print(type(hello()))
print(type(world))

# 函数互相调用
def sun():
    """
    定义一个信息打印的函数，该函数不返回任何数据
    :return:
    """
    print("Hello my friends,good morning")
def hello(): # 命名要遵循标识符要求
    """
    定义一个信息获取的功能函数操作
    :return:返回给调用处显示的内容
    """
    sun() # 调用其它函数
    return "hello world"
print(hello()) # 调用函数，直接进行返回内容的输出
world = hello() # 进行返回值的接收
print(world) # 进行返回值的输出
# Python中函数实际上也属于一个结构体，那么这个结构体可以直接进行类型获取
print(type(hello()))
print(type(world))

"""

"""