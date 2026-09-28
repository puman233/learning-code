"""
静态方法特点：
    需要通过装饰器@staticmethod来进行修饰，静态方法既不需要传递类对象也不需要传递实例对象(形参没有self/cls)
    静态方法也能通过实例对象和类对象去访问

使用场景：
    当方法中既不需要使用实例对象（如实例对象，实例属性），也不需要使用类对象（如类属性、类方法、创建实例等）时，定义静态方法
    取消不需要的参数传递，有利于减少不必要的内存占用和性能消耗
"""


class Dog(object):
    @staticmethod
    def info_print():
        print("此为静态方法")


# 创建对象
wangcai = Dog()

# 调用静态方法： 类 和 对象
wangcai.info_print()
Dog.info_print()
