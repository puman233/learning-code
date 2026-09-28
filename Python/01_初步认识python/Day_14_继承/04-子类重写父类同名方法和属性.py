# 故事：daqiu掌握了师傅和培训的技术后，自己潜心专研出独门配方的一套全新的煎饼果子

class Master(object):
    def __init__(self):
        self.kongfu = '[古法煎饼果子配方]'

    def make_cake(self):
        print(f'运用{self.kongfu}制作煎饼果子')


class School(object):
    def __init__(self):
        self.kongfu = '[黑马煎饼果子配方]'

    def make_cake(self):
        print(f'运用{self.kongfu}制作煎饼果子')


# 定义徒弟类，继承师傅类和学校类，添加和父类同名的属性和方法
class Prentice(Master, School):
    def __init__(self):
        super().__init__()
        self.kongfu = '[独创煎饼果子配方]'

    def make_cake(self):
        print(f'运用{self.kongfu}制作煎饼果子')


# 调用实例
daqiu = Prentice()
print(daqiu.kongfu)
daqiu.make_cake()

"""
结论：
如果子类和父类属性有同名的属性和方法，
子类创建对象调用属性和方法，
调用的是子类里面的同名属性和方法
"""