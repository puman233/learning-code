"""
    需求：
        有变量a=10,b=20
        交换两个变量的值
"""
a = 10
b = 20
# 方法一
# 借助第三变量储存数据
c = 0
c = a
a = b
b = c

print(a)
print(b)


print("-"*50)


apple = 1
boy = 2
# 方法二
print(apple)
print(boy)
apple,boy = boy,apple
print(apple)
print(boy)



