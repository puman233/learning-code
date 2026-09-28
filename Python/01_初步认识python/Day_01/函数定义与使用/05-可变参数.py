"""
    可变参数
·函数是实现某些复杂的操作，那么就必然牵扯到参数的接受，按照之前定义的参数形式，
    会发现，只要定义了几个参数，砸在进行函数调用的时候就必须明确的传递几个参数，
    那么为了灵活的使用参数在Python中提供有可变参数的形式，所有的可变参数都使用元祖进行接收
"""
"""
·例子
    定义可变参数
"""
def math(cmd,*numbers):
    """
    定义一个可变参数实现数学计算，可以通过传入的数学命令执行数学处理
    :param cmd: 命令符号
    :param numbers: 要接受的数据信息，为可变参数，是一个元祖
    :return:数学计算的结果
    """
    print("可变参数numbers类型：%s，参数数量：%d" % (type(numbers),len(numbers))
    sum = 0 # 保存计算的数据结果
    if cmd == "+":
        for num in numbers:
            sum += num
    elif cmd == "-":
        for num in numbers:
            sum -= num
    return sum
print("数字累加计算：%d" % math("+",1,2,3,4,5,6,7,8,9))
print("数字累减计算：%d" % math("+",1,2,3,4,5,6,7,8,9))
