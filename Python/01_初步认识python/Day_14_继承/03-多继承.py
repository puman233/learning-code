# 故事推进: daqiu是个爱学习的好孩子，想学习更多的煎饼果子技术，于是，在百度搜索到黑马程序员，报班学习煎饼果子技术。'

# 多继承就是一个类同时继承多个父类

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
