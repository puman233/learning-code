"""
    函数递归调用
·函数的递归调用指的是一个函数自己调用自己的情况
·往往需要考虑几个处理条件：
    ·需要明确定义一个递归调用的结束条件
    ·每一次调用的时候都需要修改相应的参数内容
"""
# 实现 1~100 的累加，采用递归的形式完成
def sum(num):
    """
    实现数据的累加操作，并返回累加后的计算结果
    :param num: 要执行数据累加的最大值
    :return:累加结果
    """
    if(num == 1):
        return 1    # 不管多大的数字累加，总有一个头
    return num + sum(num - 1)   # 每次调用修改参数的内容
print(sum(50))


# 实现一个阶乘运算：“1！ + 2！ + …… + 50！”
def hello(number):
    """
    实现数据阶乘计算
    :param number: 进行阶乘的数字
    :return: 数字结成结果
    """
    if(number == 1):
        return 1
    return number * hello(number - 1)
print(hello(100))
