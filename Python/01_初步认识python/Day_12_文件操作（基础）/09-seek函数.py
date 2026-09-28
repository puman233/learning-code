"""
seek() 函数
作用：用来移动文件指针
语法：文件对象.seek(偏移量,起始位置)
起始位置：
    0 文件开头
    1 当前位置
    2 文件结尾
"""

# f = open('test.txt', 'r+')

f = open('test.txt', 'a+')

# 1.改变读取数据开始位置
# f.seek(2, 0)
# f.seek(0, 0)
f.seek(0)   # 表示不改变偏移量，起始位置在文件开头

con = f.read()
print(con)

f.close()
