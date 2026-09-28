"""
类属性就是类对象所拥有的属性，它被该类的所有实例对象所共有。
类属性可以使用类对象或实例对象访问。

类属性的优点：
    记录的某项数据始终保持—致时，则定义类属性。
    实例属性要求每个对象为其单独开辟一份内存空间来记录数据，而类属性为全类所共有，仅占用一份内存，更加节省内存空间。
"""


class Dog(object):
    teeth = 10


wangcai = Dog()
xiaobai = Dog()

print(Dog.teeth)
print(wangcai.teeth)
print(xiaobai.teeth)


