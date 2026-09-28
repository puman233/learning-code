"""
self是指调用该函数的对象
"""


# 类：洗衣机 | 功能：洗衣粉
class Washer():
    def wash(self):
        print("I can wash the clothes!")
        print(self)


haier = Washer()
print(haier)

haier.wash()

# 打印对象和打印self的内存地址相同
# self指的是调用该函数的对象


