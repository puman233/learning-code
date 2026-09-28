import turtle

L = 50  # 边长
N = 12  # 角的个数
jiaodu = 180 - 360 / (N)  # 每个三个型相对于上一个三角的角度，left转动
tl = turtle.Turtle()  # 海龟的对象
# tl.speed(0)
tl.screen.delay(0)  # 绘画延时为0


def f1():
    tl.fillcolor("yellow")  # 三角形填充颜色
    tl.begin_fill()  # 填充开始
    for i in range(3):
        tl.fillcolor()
        tl.forward(L)
        tl.right(120)
    tl.end_fill()  # 填充结束


# 画外部的三角
for i in range(N):
    tl.left(jiaodu)  # 下一个三角形的角度
    tl.penup()
    tl.forward(L)  # 新三角的起始位置
    tl.pendown()
    tl.right(180)  # 转动到画三角形的相对0度
    f1()

# 画内部的多边形
tl.fillcolor("red")  # 填充颜色
tl.begin_fill()
for i in range(N):
    tl.left(jiaodu)
    tl.forward(L)
    tl.right(180)  # 转动到画三角形的相对0度
tl.end_fill()
tl.screen.mainloop()