"""
一个类可以创建多个对象，
可以用【传参数】对不同的对象设置不同的初始化属性
"""


# 定义类
class Washer():
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def print_info(self):
        print(f"洗衣机的高度是{self.height}，宽度是{self.width}")


# 创建对象 | 创建多个对象且属性值不同：调用实例方法
haier1 = Washer(10, 20)
haier1.print_info()

haier2 = Washer(100, 300)
haier2.print_info()
