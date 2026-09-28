"""
    项目类型：游戏
    项目名称：数字炸弹
    开发语言：Python
    开发时间：2020/7/23
"""

# 导包
import random
import time

# 设置游戏竞猜范围：0~1000
# 设置随机数，范围：0~1000
bomb = random.randint(1, 999)
# print(bomb)
start = 0
end = 1000
while 1 == 1:

    people = int(input('请输入 {} 到 {} 之间的数:'.format(start, end)))
    if people > bomb:
        print('大了')
        print('')
        end = people
    elif people < bomb:
        print('小了')
        print('')
        start = people
    else:
        print('玩家 >>> BOOM!!!')
        print('玩家失败    电脑获胜')
        break
    print("""
等待电脑了输入 {} 到 {} 之间的数:
    """.format(start, end))
    time.sleep(1) # 等待1秒，等候电脑输入
    print("""请等候电脑输入
    """)
    time.sleep(1)
    com = random.randint(start + 1, end - 1)
    print('电脑输入：{}'.format(com))
    if com > bomb:
        print('大了')
        print('')
        end = com
    elif com < bomb:
        print('小了')
        print('')
        start = com
    else:
        print('电脑 >>> BOOM!!!')
        print('电脑失败    玩家获胜')
        break
# 输出最终结果
print("""
        最终结果为
        {}""".format(bomb))
