class Master(object):
    def __init__(self):
        self.kf = '[古法煎饼果子配方]'

    def make_cake(self):
        print(f"运用{self.kf}制作煎饼果子")


class School(Master):
    def __init__(self):
        self.kf = '[黑马煎饼果子配方]'

    def make_cake(self):
        print(f"运用{self.kf}制作煎饼果子")
        # 方法二 super()带参写法
        # super(School, self).__init__()
        # super(School, self).make_cake()


class Prentice(School):
    def __init__(self):
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

    # 需求：一次性调用父类School Master的方法
    def make_old_cake(self):
        # 方法一
        # 缺点：不易更改类名；代码量大，冗余
        # School.__init__(self)
        # School.make_cake(self)
        # Master.__init__(self)
        # Master.make_cake(self)
        # 方法二
        # super(Prentice, self).__init__()
        # super(Prentice, self).make_cake()
        # 方法三 super()无参
        super().__init__()
        super().make_cake()


# 创建徒孙：用这个类创建对象
class Tusun(Prentice):
    pass


xiaoqiu = Tusun()
xiaoqiu.make_cake()
xiaoqiu.make_master_cake()
xiaoqiu.make_school_cake()
