# 需求：洗衣机。 功能：洗衣服

# 1.定义洗衣机类
"""
class 类名():
    代码
"""


class Washer:
    def wash(self):
        print("I can wash the clothes!")


# 2.创建对象
# 对象名 = 类名()
haier = Washer()

# 3.验证成功
# 打印 haier 对象
print(haier)

# 使用wash功能 —— 实例方法 = 对象方法 —— 对象名.wash()
haier.wash()

