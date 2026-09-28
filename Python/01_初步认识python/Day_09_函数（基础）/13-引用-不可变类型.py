"""
在Python中，值是靠引用来传递的

id()来判断两个变量是否为同一个值的引用
"""

a = 1
b = a

print(b)

# a和b值是相同的
print(id(a))
print(id(b))

# 修改a值 测试id值
a = 2
print(b)    # 说明int类型为不可变类型


# 因为修改了a的数据，内存要开辟另外一份内存取储存2，id检测a和b的值不同
print(id(a))
print(id(b))



