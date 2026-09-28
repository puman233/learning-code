# 继承：子类默认继承父类的所有属性和方法
# 所有类默认继承 object 类，object 类是顶级类或基类；
# 其它子类叫派生类

# 定义父类
class A(object):
    def __init__(self):
        self.num = 0

    def info_print(self):
        print(self.num)


# 定义子类
class B(A):
    def __init__(self):
        super().__init__()
        self.k = self.num + 1

    def info_print(self):
        print(self.k)


class C(B):
    def info_print(self):
        print(self.k)


result = C()
result.info_print()
