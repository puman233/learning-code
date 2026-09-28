"""
    元组数据不支持修改，只支持查找

    · 按下标查找数据
    · index():  查找某个数据，如果数据存在返回对应的下标，否则报错，语法和列表、字符串的index方法相同
    · count():  统计某个数据在当前元组出现的次数
    · len():    统计元组中数据的个数
"""
t1 = ('aa','bb','cc','dd',12)

# 下标
print(t1[1])    # bb

# index()
print(t1.index('aa'))   # 0
# print(t1.index('ddd'))  # 报错

# count()
print(t1.count('aa'))   # 1
print(t1.count('ddd'))  # 不存在的数据返回0次

# len()
print(len(t1))
