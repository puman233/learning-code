"""
    变量作用域
·不同范围内使用的变量采用【就近原则】
    ·LEGB原则：
        ·‘L’（Local）：函数内部变量名称’；
        ·‘E’（Enclosing Function Locals）：外部嵌套函数变量名称
        ·‘G’（Global）：函数所在模块或程序文件的变量名称；
        ·‘B’（Builtin）：内置模块的变量名称
"""
# 内置模块的变量
print(type(print))


# 观察局部变量
num = 100   # 该变量定义在了文件里面，为全局变量
def sum():
    print(num)
sum()


# 在函数中定义的变量
def hello():
    num = 100   # 定义在函数中的变量
def world():
    print(num)
world()


# 观察全局变量与函数变量之间的关系
num = 50    # 全局变量
def hi():
    """
    修改 num 变量内容
    :return:
    """
    num = 100   # 定义局部变量
    print("hi()函数中的 num 变量为：%d" % num)
hi()


# 使用 Golbal 调用全局变量
hum = 50    # 全局变量
def hold():
    """
    修改 hum 变量内容
    :return:
    """
    hold = 100   # 访问的是全局变量
    print("hold()函数中的 hum 变量为：%d" % hold)
hold()

