"""
在Python中，可以为实例属性和方法设置私有权限，即设置某个实例属性或实例方法不继承给子类。
故事: daqiu把技术传承给徒弟的同时，不想把自己的钱(2000000个亿)继承给徒弟，这个时候就要为钱这个实例属性设置私有权限。
设置私有权限的方法:在属性名和方法名前面加上两个下划线__
"""


class Master(object):
    def __init__(self):
        self.kf = '[古法煎饼果子配方]'

    def make_cake(self):
        print(f"运用{self.kf}制作煎饼果子")


class School(object):
    def __init__(self):
        self.kf = '[黑马煎饼果子配方]'

    def make_cake(self):
        print(f"运用{self.kf}制作煎饼果子")


class Prentice(School, Master):
    def __init__(self):
        self.kf = '[独创煎饼果子配方]'
        # 定义私有属性
        self.__money = 2000000

    # 定义私有方法
    def __info_print(self):
        print("私有方法")
        print(self.kf)
        print(self.__money)

    def make_cake(self):
        # 若先调用父类的同名方法和属性，父类属性会覆盖子类属性，故在调用属性前，先调用自己自类的初始化
        self.__init__()
        print(f"运用{self.kf}制作煎饼果子")

    # 子类调用父类的同名方法和属性，把父类的同名方法和属性再次封装
    def make_master_cake(self):
        # 父类类名.函数()
        # 再次利用初始化的原因，这里调用父类的同名方法和属性，属性在init初始化设置，所以需要再次调用init
        Master.__init__(self)
        Master.make_cake(self)

    def make_school_cake(self):
        School.__init__(self)
        School.make_cake(self)


class Tusun(Prentice):
    pass


xiaoqiu = Tusun()
print(xiaoqiu.__money)  # 报错：私有属性无法调用

xiaoqiu.__info_print()  # 报错

