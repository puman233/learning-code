import time
import random


def kill_code():
    # 终止代码
    exit(code=0)


# 变量
player_before = 0
# 列表
scores_player = []
scores_computer_1 = []
scores_computer_2 = []


def main_3():
    # 欢迎界面
    print("""
            欢迎您来到猜拳游戏
            """)
    print("-" * 40)  # 分割上下界面

    def gz():  # 规则函数
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

    gz()  # 调用规则函数

    def check():  # 检查窗口
        # 主检查 & 判断

        # 1.出拳
        # 玩家：
        global computer_1, int_player, computer_2
        player = input("请出拳：")
        int_player = int(player)
        if int_player == player_before:
            print("玩家出 石头")
        elif int_player != player_before and int_player == 1:
            print("玩家出 剪刀")
        elif int_player != player_before and int_player == 2:
            print("玩家出 布")
        time.sleep(1)
        # 电脑一号:
        computer_1 = random.randint(0, 2)  # 随机选择电脑出的数字(也就是电脑出的拳)
        if computer_1 == 0:
            print("①号电脑出 石头")
        else:
            if computer_1 == 1:
                print("①号电脑出 剪刀")
            elif computer_1 == 2:
                print("①号电脑出 布")
        time.sleep(1)
        # 电脑二号
        computer_2 = random.randint(0, 2)
        if computer_2 == 0:
            print("②号电脑出 石头")
        else:
            if computer_2 == 1:
                print("②号电脑出 剪刀")
            elif computer_2 == 2:
                print("②号电脑出 布")
        # 2.判断输赢
        print("请等待程序计算……")
        time.sleep(1)
        # 玩家获胜 | 玩家 0，① 1，② 1 & 玩家 1，① 2，② 2 & 玩家 2，① 0，② 0
        if int_player == 0 and computer_1 == 1 and computer_2 == 1:
            print("【玩家获胜】恭喜您！")
            scores_player.append(1)
        elif int_player == 1 and computer_1 == 2 and computer_2 == 2:
            print("【玩家获胜】恭喜您！")
            scores_player.append(1)
        elif int_player == 2 and computer_1 == 0 and computer_2 == 0:
            print("【玩家获胜】恭喜您！")
            scores_player.append(1)
        # 平局
        else:
            # 情况-1
            if int_player == computer_1 == computer_2:
                print("【平局】")
            # 情况-1
            elif int_player == 0 and computer_1 == 1 and computer_2 == 2:
                print("【平局】")
            elif int_player == 0 and computer_1 == 2 and computer_2 == 1:
                print("【平局】")
            elif int_player == 1 and computer_1 == 2 and computer_2 == 0:
                print("【平局】")
            elif int_player == 1 and computer_1 == 0 and computer_2 == 2:
                print("【平局】")
            elif int_player == 2 and computer_1 == 0 and computer_2 == 1:
                print("【平局】")
            elif int_player == 2 and computer_1 == 1 and computer_2 == 0:
                print("【平局】")
            # 电脑获胜 | 玩家 0，① 2，② 2 & 玩家 1，① 0，② 0 & 玩家 2，① 1，② 1
            elif int_player == 0 and computer_1 == 2 and computer_2 == 2:
                print("【电脑获胜】")
                scores_computer_1.append(1)
                scores_computer_2.append(1)
            elif int_player == 1 and computer_1 == 0 and computer_2 == 0:
                print("【电脑获胜】")
                scores_computer_1.append(1)
                scores_computer_2.append(1)
            elif int_player == 2 and computer_1 == 1 and computer_2 == 1:
                print("【电脑获胜】")
                scores_computer_1.append(1)
                scores_computer_2.append(1)
            elif int_player == 0 and computer_1 == 0 and computer_2 == 2:
                print("【②号电脑】获胜")
                scores_computer_2.append(1)
            elif int_player == 0 and computer_1 == 2 and computer_2 == 0:
                print("【①号电脑】获胜")
                scores_computer_1.append(1)
            elif int_player == 1 and computer_1 == 1 and computer_2 == 0:
                print("【②号电脑】获胜")
                scores_computer_2.append(1)
            elif int_player == 1 and computer_1 == 0 and computer_2 == 1:
                print("【①号电脑】获胜")
                scores_computer_1.append(1)
            elif int_player == 2 and computer_1 == 2 and computer_2 == 1:
                print("【②号电脑】获胜")
                scores_computer_2.append(1)
            elif int_player == 2 and computer_1 == 1 and computer_2 == 2:
                print("【①号电脑】获胜")
                scores_computer_1.append(1)
            # 特殊情况
            # 两个人同时获胜 | 0 石头 & 1 剪刀 & 2 布
            elif int_player == 2 and computer_1 == 2 and computer_2 == 0:
                print("【玩家】和【①号电脑】获胜")
                scores_player.append(1)
                scores_computer_1.append(1)
            elif int_player == 2 and computer_1 == 0 and computer_2 == 2:
                print("【玩家】和【②号电脑】获胜")
                scores_player.append(1)
                scores_computer_2.append(1)
            elif int_player == 1 and computer_1 == 1 and computer_2 == 2:
                print("【玩家】和【①号电脑】获胜")
                scores_player.append(1)
                scores_computer_1.append(1)
            elif int_player == 1 and computer_1 == 2 and computer_2 == 1:
                print("【玩家】和【①号电脑】获胜")
                scores_player.append(1)
                scores_computer_1.append(1)
            elif int_player == 0 and computer_1 == 0 and computer_2 == 1:
                print("【玩家】和【①号电脑】获胜")
                scores_player.append(1)
                scores_computer_1.append(1)
            elif int_player == 0 and computer_1 == 1 and computer_2 == 0:
                print("【玩家】和【②号电脑】获胜")
                scores_player.append(1)
                scores_computer_2.append(1)

    # 询问用户：玩几局
    print("请问您是要玩几局游戏呢？")
    key_num = int(input())

    for i in range(key_num):
        if type(key_num) == int:
            int_key_num = key_num
            if int_key_num == 0:
                kill_code()
            else:
                if int_key_num >= 1:
                    print("让我们开始吧！")
                    time.sleep(0.25)
                    check()
        else:
            if type(key_num) == str:
                kill_code()


main_3()

end_player = len(scores_player)
end_computer_1 = len(scores_computer_1)
end_computer_2 = len(scores_computer_2)

print("-" * 20)
print(f"玩家共赢了{end_player}局游戏")
print(f"①号电脑共赢了{end_computer_1}局游戏")
print(f"②号电脑共赢了{end_computer_2}局游戏")
print("-" * 5)


def to():
    # 奖励代码
    if end_player > end_computer_1 > end_computer_2:
        print("MVP：玩家")
        if 3 <= end_player < 5:
            print(f"本轮游戏玩家赢了{end_player}局 | 前途无量！")
        elif end_player == 5:
            print("本轮游戏玩家赢了5局 | 5杀！还有谁？")
        elif 5 < end_player < 10:
            print(f"本轮游戏玩家共赢了{end_player}局 | 锋芒毕露！")
        elif end_player >= 10:
            print(f"本轮游戏玩家共赢了{end_player}局 | 无人能敌！")
    elif end_computer_1 < end_player < end_computer_2:
        print("MVP：②号电脑")
    elif end_player < end_computer_1 < end_computer_2:
        print("MVP：①号电脑")
        print("玩家 再接再厉！")
    elif end_player < end_computer_1 < end_computer_2 and end_computer_1 == end_computer_2:
        print("MVP：电脑玩家")
        print("玩家 再接再厉！")


print()

to()
