"""
属性即是特征

对象属性既可以在类外面添加和获取，也可以在类里面添加和获取。

类外面添加对象属性：
    - 语法：
        对象名.属性名 = 值
    - 例子：
        haier1.width = 500
        haier1.height = 800

类外面获取对象属性
    - 语法
        对象名.属性名
"""


class Washer():
    def wash(self):
        print("I can wash the clothes!")


haier1 = Washer()

# 添加属性 对象名.属性名 = 值
haier1.width = 400
haier1.height = 500

# 获取属性
print(f"洗衣机的宽度是{haier1.width}")
print(f"洗衣机的高度是{haier1.height}")


