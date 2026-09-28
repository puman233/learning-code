"""
    需求：一次打印列表中的各个数据

    while
"""

name_list = ['Tom','Amy','Rose']

"""
    - 准备表示下标数据
    - 循环while
        · 条件 a < 3 len()
        · 遍历：依次按顺序访问到序列的每一个数据
        · a += 1
"""
a = 0
while a < len(name_list):
    print(name_list[a])
    a += 1