#


class Master(object):
    def __init__(self):
        self.Kongfu = '[古法煎饼果子配方]'

    def make_cake(self):
        print(f"运用{self.Kongfu}制作煎饼果子")


class School(object):
    def __init__(self):
        self.Kongfu = '[黑马煎饼果子配方]'

    def make_cake(self):
        print(f"运用{self.Kongfu}制作煎饼果子")


class Prentice(School, Master):  # 先继承 School
    pass


result = Prentice()
print(result.Kongfu)
result.make_cake()

print(Prentice.__mro__)
