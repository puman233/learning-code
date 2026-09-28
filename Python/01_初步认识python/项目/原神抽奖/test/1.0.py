import random

role5 = ['钟离', '甘雨', '温迪', '雷电将军', '荒泷一斗']
role4 = ['烟绯', '行秋', '北斗', '班尼特', '凝光', '香菱', '砂糖', '重云', '九条裟罗', '五郎', '迪奥娜', '诺艾尔']


def achieve(roleFive=0.0061, roleFour=0.949):
    a = random.random()
    if a <= roleFive:
        print("5星")
        role = random.randint(0, 4)
        print("角色为："+role5[role])
        return 0
    elif a >= roleFour:
        print("4星")
        role = random.randint(0, 11)
        print("角色为："+role4[role])
        return 1
    else:
        print("没有抽中")
        return 2


class main(object):
    def __init__(self, roleFive=0.0061, roleFour=0.949):
        self.roleFive = roleFive
        self.roleFour = roleFour

    def riseRole(self, times):
        for i in range(times):
            x = achieve(roleFive=self.roleFive, roleFour=self.roleFour)
            if x == 2:
                self.roleFive += 0.011
                self.roleFour -= 0.094
            elif x == 0:
                self.roleFive = 0.0061
            elif x == 1:
                self.roleFour = 0.949


if __name__ == '__main__':
    choose = "y"
    roleFive = 0.0061
    roleFour = 0.949
    result = main()
    while choose == "y":
        result.riseRole(10)
        choose = input("请按 y 继续，按其它键退出：")
