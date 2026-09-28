"""
需求：任意两个数字，按照指定要求整理数字后再进行求和计算

注意：
    两种方法对比之后，发现方法2的代码会更加简洁，函数灵活性更高
函数式编程大量使用函数，减少了代码的重复，因此程序比较短，开发速度较快
"""


# 1. 写法一
def add_num(a, b):
    # 绝对值
    return abs(a) + abs(b)


result = add_num(-1.1, 1.9)
print(result)


# 2.写法二：高阶函数：f是第三个参数，用来接收数据传入的数据
def sum_num(a, b, f):
    return f(a) + f(b)


result1 = sum_num(-1, 5, abs)
print(result1)

result2 = sum_num(1.1, 1.3, round)
print(result2)

print("——————————分割线——————————")


# 案例
def all():
    def sum_num(a, b, f):
        return f(a) + f(b)

    print("绝对值 1 | 四舍五入 2")
    qus = int(input("请问您是想做两个数和的绝对值还是进行四舍五入呢？"))
    if qus == 1:
        f = abs
        print("进行绝对值计算")
        key1 = int(input("请输入第一个数字：")) or float(input("请输入第一个数字："))
        key2 = int(input("请输入第二个数字：")) or float(input("请输入第二个数字："))
        result3 = sum_num(key1, key2, f)
        print(result3)
    elif qus == 2:
        f = round
        print("进行四舍五入计算")
        key1 = float(input("请输入第一个数字：")) or int(input("请输入第二个数字："))
        key2 = float(input("请输入第二个数字：")) or int(input("请输入第二个数字："))
        result4 = sum_num(key1, key2, f)
        print(result4)
    else:
        print("您的输入有误，程序报错，退出")
        exit(0)


while True:
    all()
