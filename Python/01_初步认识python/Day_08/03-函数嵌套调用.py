# 所谓函数嵌套调用指的是一个函数里面又掉用了另外一个函数

# 两个函数 testA 和 textB————在A里面调用B

# B函数
def testB():
    print("B函数开始……")
    print("这是B函数")
    print("B函数开始……")

# A函数
def testA():
    print("A函数开始……")
    testB()
    print("A函数结束……")


testA()

