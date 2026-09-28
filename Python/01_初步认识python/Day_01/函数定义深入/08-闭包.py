"""
    闭包
·指函数中一种嵌套结构，内部函数可以方便的使用外部函数中定义的内容，并且可以保持状态的一致性
·内部的嵌套结构受到外部的制约，这就是闭包的操作特点
"""
# 在内部函数修改外部函数变量
def hello(count):
    def world(data):
        nonlocal count  # 使用nonlocal关键字描述本次不是本地变量
        # 如果此时的count变量不加入任何的修改，那么即表示本地变量
        count += 1  # 修改外部函数的参数内容
        return "第{}次输入数据：{}".format(count,data)
    return world
a = hello(0)
print(a("https://www.csdn.net"))
print(a("https://www.csdn.net"))
print(a("https://www.csdn.net"))
print(a("https://www.csdn.net"))
print(a("https://www.csdn.net"))
print(a("https://www.csdn.net"))
print(a("https://www.csdn.net"))
print(a("https://www.csdn.net"))
print(a("https://www.csdn.net"))
