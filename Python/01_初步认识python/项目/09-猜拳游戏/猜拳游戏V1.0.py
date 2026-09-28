# 导包
import os
import random
import time

"""
    猜拳游戏 V1.52
    
    新增功能：                           版本号：                发行时间：
        · 主题代码实现                    V1.0                2021/5/1 - 15:30
        · 优化程序                       V1.32               2021/5/1 - 20:30
        · for循环实现游戏次数              V1.52               2021/5/2 - 21:30
    
    （已停更——2021/5/1）
"""


def MainCQ_1():
    def CQYX():
        """
        1. 出拳
            玩家：手动输入
            电脑：1.1 固定：剪刀
            1.2 随机
        2.判断输赢
            2.1 玩家获胜
            2.2 平局
            2.3 电脑获胜
        """
        # 欢迎界面
        print("""
        欢迎您玩'猜拳游戏'
        """)

        # 1.出拳
        # 玩家：
        Player = int(input("请出拳：输入‘0’出石头；输入‘1’出剪刀；输入‘2’出布："))
        if Player == 0:
            print("玩家出 石头")
        else:
            if Player == 1:
                print("玩家出 剪刀")
            if Player == 2:
                print("玩家出 布")
        # 电脑:
        time.sleep(1)
        Computer = random.randint(0, 2)  # 随机选择电脑出的数字(也就是电脑出的拳)
        # print(Computer)
        if Computer == 0:
            print("电脑出 石头")
        else:
            if Computer == 1:
                print("电脑出 剪刀")
            if Computer == 2:
                print("电脑出 布")
        # 2.判断输赢
        # 玩家获胜
        time.sleep(1)
        if ((Player == 0) and (Computer == 1)) or ((Player == 1) and (Computer == 2)) or (
                (Player == 2) and (Computer == 0)):
            print("""
            玩家获胜，恭喜你！""")
        # 平局
        elif Player == Computer:
            print("""
                平局！
            玩家别走，再来一局！""")
        else:
            print("""
            电脑获胜""")

    # 总共完成十局游戏

    for i in range(10):
        CQYX()
        print("十次游戏结束")


# 试验区：
# 猜拳游戏
MainCQ_1()

