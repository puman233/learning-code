"""
一般在实际开发过程中，一个程序往往有多个函数组成
并且多个函数共享某些数据
"""

glo_num = 0

def test1():
    global glo_num
    glo_num = 100


def test2():
    print(glo_num)


print(glo_num)  # 因为修改的函数未执行
test1()
test2()  # 100 先到用了函数1
print(glo_num)  # 100 调用了函数1


