"""
    tuple() 将某个序列转换成元组

    list()   转换成列表

    set()   转换成集合
"""
list1 = [10,20,30,40,50]
s1 = {100,300,200,500}
t1 = ('a','b','c','d','e')

# tuple()
print(tuple(list1))
print(tuple(s1))
# list()
print(list(s1))
print(list(t1))
# set()
print(set(list1))
print(set(s1))