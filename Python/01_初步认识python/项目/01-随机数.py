"""
随机做法：
    1. 导出 random 模块
        inport 模块名
    2.使用 random 模块中的随机整数功能
        random.randint（开始，结束）
"""

"""
步骤
    1. 导入模块
    import random
    2. 使用这个模块中的功能
    random.randint()
"""


import random

num = random.randint(0, 9999999999999999999)

print(num)

list = ['1', '2', '3']

print(random.choice(list))  # 从序列中随机选取一个元素

index = random.choice(list)
print(index)


def random_index(rate):
    start = 0
    index = 0
    randnum = random.randint(1, sum(rate))

    for index, scope in enumerate(rate):
        start += scope
        if randnum <= start:
            break
    return index


def main():
    role5 = ['钟离']
    role4 = ['烟绯', '行秋', '北斗']
    arr = [role5, role4]
    rate = [6, 94]

    role5_times = 0
    role4_times = 0
    count = 0
    for i in range(1000):
        count += 1
        index = random_index(rate)
        if arr[index] == role5:
            role5_times += 1
        elif arr[index] == role4:
            role4_times += 1

    print(count, role5_times, role4_times)


if __name__ == '__main__':
    main()
