# 故事；很多顾客都希望吃到古法和黑马技术的煎饼果子

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
        super().__init__()
        self.kf = '[独创煎饼果子配方]'

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


daqiu = Prentice()
daqiu.make_master_cake()
daqiu.make_school_cake()

