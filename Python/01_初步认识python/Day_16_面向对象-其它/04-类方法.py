"""
类方法特点：
    需要用装饰器@classmethod来标识其为类方法，对于类方法，第一个参数必须是类对象，一般以cls作为第一个参数。

类方法使用场景：
    当方法中需要使用类对象(如访问私有类属性等)时，定义类方法
    类方法一般和类属性配合使用
"""


class Dog(object):
    __teeth = 10

    @classmethod
    def get_teeth(cls):
        return cls.__teeth


wangcai = Dog()
result = wangcai.get_teeth()
print(result)


class Studying(object):
    __students = ['Tom', 'Amy', 'Jok']
    __teacher = ['Smith', 'John', 'Bob']

    @classmethod
    def get_students(cls):
        return cls.__students

    def get_teacher(cls):
        return cls.__teacher


Study = Studying()
results = Study.get_students()
results2 = Study.get_teacher()
print(results, results2)
