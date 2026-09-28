import random

role5 = ['钟离']
role4 = ['烟绯', '行秋', '北斗', '西风长枪']
role3 = ['黑缨枪', '长枪', '白缨枪', '黑影阔剑', '翡翠玉球']


class Master(object):
    def buy(self):
        numStone = int(input("请问您要充值多少原石？"))
        self.protostone += numStone
        self.money -= numStone / 12
        print(f"您现在有{self.protostone}个原石，{self.money}元")

    # 初始
    def __init__(self):
        # 初始值
        self.protostone = 0  # 原石
        self.Entanglement = 24  # 纠缠之缘
        self.money = 12000  # 虚拟金额
        print("""
        1. 充值原石 ____ 1元/2个
        2. 购买纠缠之缘
        3. 抽卡池
        """)
        key = int(input("您要进行的操作："))
        if key == 1:
            result1 = Master()
            result1.buy()
        elif key == 2:
            numEntanglement = int(input("请问您要购买多少纠缠之缘？"))
            num = self.protostone - 160 * numEntanglement
            if num > 0:
                self.Entanglement += num
            elif num < 0:
                gap = 160 * numEntanglement - self.protostone
                try_key = int(input(f"您还差{gap}个原石，按1充值？按2跳过"))
                if try_key == 1:
                    result2 = Master()
                    result2.buy()
                elif try_key == 2:
                    pass
        elif key == 3:
            pass
            # if __name__ == '__main__':
            #     choose = "y"
            #     roleFive = 0.0006
            #     roleFour = 0.0866
            #     result = main()
            #     while choose == "y":
            #         result.riseRole(10)
            #         choose = input("请按 y 继续，按其它键退出：")


# 实现概率
def achieve(roleFive=0.0006, roleFour=0.0866, roleThree=0.9128):
    a = random.random()
    if a <= roleFive:
        print("5星")
        role = random.randint(0, 1)
        print(role5[role])
        return 0
    elif roleFive < a <= roleFour:
        print("4星")
        role = random.randint(0, 6)
        print(role4[role])
        return 1
    elif a > 1 - roleThree:
        print("三星")
        role = random.randint(0, 4)
        print(role3[role])
        return 2
    else:
        print("没有抽中")
        return 3


# 核心类：祈愿概率
class main(object):
    def __init__(self, roleFive=0.0006, roleFour=0.0866, roleThree=0.9128):
        self.roleFive = roleFive
        self.roleFour = roleFour
        self.roleThree = roleThree

    def riseRole(self, times):
        for i in range(times):
            x = achieve(roleFive=self.roleFive, roleFour=self.roleFour)
            if x == 2:
                self.roleFive += 0.0011
                self.roleFour -= 0.0094
            elif x == 0:
                self.roleFive = 0.0006
            elif x == 1:
                self.roleFour = 0.9128
            elif x == 3:
                self.roleFour = 0.9128
                self.roleFive = 0.0006


results = Master()
results.__init__()
