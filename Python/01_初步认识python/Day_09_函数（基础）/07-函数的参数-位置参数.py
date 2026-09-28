"""
    位置参数：
        调用函数时根据函数定义的参数位置来传递参数
    注意：
        传递和定义参数的顺序及个数必须一致

"""


def user_info(name,age,gender):
    print(f"您的名字是{name}，年龄是{age}，性别是{gender}")


user_info('Tom',20,'男')

