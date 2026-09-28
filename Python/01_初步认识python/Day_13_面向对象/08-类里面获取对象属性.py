"""
语法：
    self.属性名
"""


# 定义类
class Washer():
    def wash(self):
        print("I can wash the clothes")

    def print_info(self):
        # 类里面获取实例属性
        print(f"haier1洗衣机的宽度是{self.width}")
        print(f"haier1洗衣机的高度是{self.height}")


# 创建对象
haier1 = Washer()

# 添加实例属性
haier1.width = 400
haier1.height = 800

haier1.print_info()
