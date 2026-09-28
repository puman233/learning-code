"""
烤地瓜

需求：
    1.被烤的时间和对应的状态
        0~3分钟 | 生的
        3~5分钟 | 半生不熟
        5~8分钟 | 熟的
        > 8分钟 | 烤糊了

    2.添加的调料
        用户可以按自己的意愿添加调料
"""


# 定义类：初始化属性，被烤和添加调料的方法，显示对象信息的str
class SweetPotato:
    def __init__(self):
        # 被烤的时间
        self.cook_time = 0
        # 烤的状态
        self.cook_state = "生的"
        # 调料类表
        self.condiments = []

    def cook(self, time):
        """烤地瓜方法"""
        # 1.先计算地瓜整体考过的时间
        self.cook_time += time

        # 2.用整体考过的时间再判断地瓜的状态
        if 0 <= self.cook_time < 3:
            # 生的
            self.cook_state = "生的"
        elif 3 <= self.cook_time < 5:
            # 半生不熟
            self.cook_state = "半生不熟"
        elif 5 <= self.cook_time < 8:
            # 熟了
            self.cook_state = "熟的"
        elif self.cook_time >= 8:
            # 糊了
            self.cook_state = "糊了"

    def add_condiments(self, condiments):
        # 用户意愿的调料追加到调料列表
        self.condiments.append(condiments)

    def __str__(self):
        return f"这个地瓜烤了{self.cook_time}分钟，状态是{self.cook_state}，调料有{self.condiments}"


# 创建对象并调用对应的实例方法
goto = SweetPotato()
print(goto)

goto.cook(2)
goto.add_condiments("辣椒")
print(goto)

goto.cook(2)
goto.add_condiments("酱油")
print(goto)

