# 故事主线:一个煎饼果子老师傅，在煎饼果子界摸爬滚打多年，研发了一套精湛的摊煎饼果子的技术。
# 师父要把这套技术传授给他的唯一的最得意的徒弟。

# 师傅类
class Master(object):
    def __init__(self):
        self.Kongfu = '[古法煎果饼子配方]'

    def make_cake(self):
        print(f"运用{self.Kongfu}制作煎饼果子")


# 徒弟类
class Prentice(Master):
    pass


# 用徒弟类创建对象，调用实例属性和方法
test = Prentice()

print(test.Kongfu)

test.make_cake()
