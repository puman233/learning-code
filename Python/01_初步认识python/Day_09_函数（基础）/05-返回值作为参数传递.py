def test1():
    return 50


def test2(num):
    print(num)


# 先得到函数1的返回值，再把这个返回值传入到函数2
result = test1()
# print(result)

test2(result)



