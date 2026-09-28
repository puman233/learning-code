"""
类属性只能通过类对象修改，不能通过实例对象修改，如果通过实例对象修改类属性，表示的是创建了一个实例属性。
"""


class Dog(object):
    teeth = 10


wangcai = Dog()
xiaobai = Dog()


# 修改类属性
Dog.teeth = 12
print(Dog.teeth)
print(wangcai.teeth)
print(xiaobai.teeth)

# 通过对象修改类属性
wangcai.teeth = 16
print(wangcai.teeth)
print(xiaobai.teeth)


