# B函数想要a的取值是200
a = 100
print(a)


def testA():
    print(a)


def testB():
    a = 200  # 局部变量
    print(a)


testA()
testB()

def testC():
    # 想要修改全局变量a，值是200
    global a    # 声明a为全局变量
    a = 200
    print(a)


testC()

print(a)


