# 在Python中，一般定义函数名get_xx用来获取私有属性，定义set_xx用来修改私有属性值。
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

    # 定义函数：获取私有属性值
    def get_money(self):
        return self.__money

    # 定义函数：修改私有属性值
    def set_money(self):
        self.__money = 500

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
print(xiaoqiu.get_money())

xiaoqiu.set_money()
print(xiaoqiu.get_money())
