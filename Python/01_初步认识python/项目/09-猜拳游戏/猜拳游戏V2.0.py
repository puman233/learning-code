import time
import random

"""
    猜拳游戏 V2.92

    新增功能：                         版本号：                  发行时间：                   备注：
        · 优化【规则】界面              V2.02                   2021/5/2 - 8:30
        · 新增玩家游戏次数              V2.35                   2021/5/2 - 9:00
        · 新增一个【电脑玩家】           V2.80                   2021/5/2 - 9:30
        · 优化程序，减少报错             V2.90                   2021/5/2 - 10:00
        · 优化程序，增加补丁             V2.92                   2021/5/3 - 11:30
        · 修复已知Bug                  V2.95                   2021/5/4 - 13:50         （因某些原因，停更 | 现已迁移至V3.0版本修复）
        
    最终版本：V2.92
    （此项目已停更——2021/5/8）
"""

def main_2():
    # 欢迎界面
    global number_of_games
    print("""
            欢迎您来到猜拳游戏
            """)
    print("-" * 40)  # 分割上下界面

    def GZ():  # 规则函数
        # 显示规则
        print("规则如下：")
        print("""
                    输入：
                        0   玩家出 石头
                        1   玩家出 剪刀
                        2   玩家出 布
                    其他功能：
                        输入：
                            q   退出游戏
                            r   查看规则
                            """)
        print("【注意】：本游戏采用大量键盘输入功能，请玩家注意键盘输入时别出错哦~")

    GZ()  # 调用规则函数

    def cq():  # 主窗口
        # 1.出拳
        # 玩家：
        player = input("请出拳：")
        if type(player) == int:
            int_player = int(player)
            if int_player == 0:
                print("玩家出 石头")
            else:
                if int_player == 1:
                    print("玩家出 剪刀")
                if int_player == 2:
                    print("玩家出 布")
                # 补丁-1
                time.sleep(0.2)
                if int_player != 1 or int_player != 2 or int_player != 0:
                    print("您的输入有误")
                    print("您需要重新开始游戏"
                          "我们将为您重新启动游戏")
                    time.sleep(0.5)
                    main_2()  # 返回主程序
        else:
            if type(player) == str:
                str_player = str(player)
                if str_player == 'r' or player == 'R':
                    # 隔开上下界面
                    print("-" * 40)
                    print("·" + " " * 38 + "·")
                    print("·" + " " * 38 + "·")
                    print("·" + " " * 38 + "·")
                    print("·" + " " * 38 + "·")
                    print("·" + " " * 38 + "·")
                    print("·" + " " * 38 + "·")
                    print("-" * 40)
                    main_2()  # 显示【规则】后返回主程序
                else:
                    if str_player == 'q' or str_player == 'Q':
                        return 0
                    # 补丁-2
                    if str_player != 'r' or str_player != 'q':
                        print("您的输入有误")
                        print("您需要重新开始游戏"
                              "我们将为您重新开始游戏")
                        time.sleep(0.25)
                        main_2()  # 返回主程序
                    # 补丁-3
                    if str_player.isspace():
                        print("您的输入有误")
                        print("您需要重新开始游戏")
                        print("我们将为您重新启动游戏")
                        time.sleep(0.25)
                        main_2()  # 返回主程序

        time.sleep(0.25)

        # 电脑一号:
        print("请等待①号电脑玩家……")
        time.sleep(0.25)
        computer_1 = random.randint(0, 2)  # 随机选择电脑出的数字(也就是电脑出的拳)
        # print(Computer_1)
        if computer_1 == 0:
            print("①号电脑出 石头")
        else:
            if computer_1 == 1:
                print("①号电脑出 剪刀")
            if computer_1 == 2:
                print("①号电脑出 布")
        # 电脑二号
        print("请等待②号电脑玩家……")
        time.sleep(0.25)
        computer_2 = random.randint(0, 2)
        if computer_2 == 0:
            print("②号电脑出 石头")
        else:
            if computer_2 == 1:
                print("②号电脑出 剪刀")
            if computer_2 == 2:
                print("②号电脑出 布")

        # 2.判断输赢
        # time.sleep(0.5)
        print("请等待程序计算……")
        # 玩家获胜 | 玩家 0，① 1，② 1 & 玩家 1，① 2，② 2 & 玩家 2，① 0，② 0
        if ((player == 0) and (computer_1 == 1) and (computer_2 == 1)) or (
                (player == 1) and (computer_1 == 2) and (computer_2 == 2)) or (
                (player == 2) and (computer_1 == 0) and (computer_2 == 0)):
            print("""
            【玩家获胜】
            恭喜你！""")
        # 平局
        else:
            # 情况-1
            if player == computer_1 == computer_2:
                print("""
                    【平局】
                玩家别走，再来一局！
                """)
            # 情况-2
            if (player == computer_1 == computer_2) and (key_num == 1):
                print("""
                    【平局】
                """)
            # 情况-1
            if (player == 0) and (computer_1 == 1) and (computer_2 == 2) or (player == 1) and (
                    computer_1 == 2) and (computer_2 == 0) or (player == 2) and (
                    computer_1 == 0) and (computer_2 == 1) or (player == 0) and (
                    computer_1 == 2) and (computer_2 == 1) or (player == 1) and (
                    computer_1 == 0) and (computer_2 == 2) or (player == 2) and (
                    computer_1 == 1) and (computer_2 == 0):
                print("""
                    【平局】
                玩家别走，再来一局！
                """)
            # 情况-2
            if (player == 0) and (computer_1 == 1) and (computer_2 == 2) and (key_num == 1) or (player == 1) and (
                    computer_1 == 2) and (computer_2 == 0) and (key_num == 1) or (player == 2) and (
                    computer_1 == 0) and (computer_2 == 1) and (key_num == 1) or (player == 0) and (
                    computer_1 == 2) and (computer_2 == 1) and (key_num == 1) or (player == 1) and (
                    computer_1 == 0) and (computer_2 == 2) and (key_num == 1) or (player == 2) and (
                    computer_2 == 1) and (computer_2 == 0) and (key_num == 1):
                print("""
                    【平局】
                """)
            # 电脑获胜 | 玩家 0，① 2，② 2 & 玩家 1，① 0，② 0 & 玩家 2，① 1，② 1
            if ((player == 0) and (computer_1 == 2) and (computer_2 == 2)) or (
                    (player == 1) and (computer_1 == 0) and (computer_2 == 0)) or (
                    (player == 2) and (computer_1 == 1) and (computer_2 == 1)):
                print("""
                【电脑获胜】
                """)

        time.sleep(1.5)

    # 询问用户：玩几局游戏
    print("请问您是要玩几局游戏呢？")
    key_num = input()
    # 补丁-4
    if type(key_num) == int:
        int_key_num = int(key_num)
        if int_key_num > 20:
            print(f"wow~ 您真的要玩 {int_key_num} 局吗？")
            print("如果是，输入 1 以继续。")
            print("如果不是，输入 2 重新开始游戏。")
            # 确定功能
            determine = input(print("请输入："))
            if determine == 1:
                print(f"好的。不过{int_key_num}局游戏的时间可能太长，您可以随时按 q 以结束游戏。")
                cq()
                # 最终数 | Final_number
                final_number = int_key_num
                # 确认游戏次数 | number_of_games
                # 定义列表
                list_key = [final_number]
            else:
                if determine != 2:
                    print("好的。我们将为您重新启动游戏。")
                    main_2()
        else:
            if key_num == 0:
                k = key_num + 1
                print("玩一局？让我们开始吧！")
                cq()

                def number_of_games():
                    for num in range(final_number):
                        time.sleep(0.5)
                        cq()
                        time.sleep(1.8)
    else:
        if type(key_num) == str:
            str_key_num = str(key_num)
            if str_key_num == 'q' or str_key_num == 'Q':
                return 0
            else:
                if str_key_num == "r" or str_key_num == "R":
                    GZ()
                    time.sleep(0.5)
                    main_2()

    # 总共完成n局游戏
    number_of_games()

# 试验区

# 猜拳游戏

main_2()
