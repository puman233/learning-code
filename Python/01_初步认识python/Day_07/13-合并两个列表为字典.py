"""
    合并字典
"""

list1 = ['name','age','gender']
list2 = ['Tom',20,'man']

# 1. 如果两个列表数据个数相同，len统计任何一个列表的长度都可以
# 2. 如果两个列表数据个数不同，len统计数据多的列表数据个数会报错
# 3. len统计数据少的列表数据个数不会报错
dict1 = {list1[i]:list2[i] for i in range(len(list1))}
print(dict1)

print("-----")

# 实验 V1.0
list3 = [i for i in range(1,10)]
list4 = [q**2 for q in range(1,10)]
dict5 = {list3[i]:list4[i] for i in range(len(list3))}
print(dict5)

