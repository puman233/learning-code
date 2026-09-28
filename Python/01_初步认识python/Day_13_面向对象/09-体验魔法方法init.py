"""
Python中，__xx__()的函数叫做魔法方法， 指的是具有特殊功能的函数

__init__() 的作用：
    初始化对象

注意:
    - __init__()方法，在创建一个对象时默认被调用，不需要手动调用
    - __init__(self)中的self参数，不需要开发者传递，Python解释器会自动把当前的对象引用传递过去
"""


class Washer():
    # def __init__(self):
    #     # 添加实例属性
    #     self.width = 500
    #     self.height = 900
    def __init__(self):
        # 添加实例属性
        input_self_width = input("请输入洗衣机的宽度：")
        self.width = input_self_width
        input_self_height = input("请输入洗衣机的高度：")
        self.height = input_self_height

    def print_info(self):
        print(f"洗衣机的宽度是{self.width}")
        print(f"洗衣机的高度是{self.height}")


# 创建对象
haier = Washer()

haier.print_info()
