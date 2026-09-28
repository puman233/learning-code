"""
    需求：
        创建列表如下：
        [(1,0),(1,1),(1,2),(2,0),(2,1),(2,2)]
"""

"""
    数据1 ： 1 和 2 range(1,3)
    数据2 ： 0 1 2 range(3)
"""
# 1.设置列表
list1 = []
for i in range(1,3):
    for j in range(3):
        #列表里面追加元组，循环前准备一个空列表，然后这里追加元组数据到列表
        list1.append((i,j))
print(list1)


# 多个for循环实现列表推导式
list2 = [(i,j) for i in range(1,3) for j in range(3)]
print(list2)

print('-'*20)

# 实验
# 需求： [(1,0,0),(1,0,1),(1,0,2)...(1,1.0),(1,1,1),(1,1,2)...(1,9,8),(1,9,9),(2,0,0)]
# 1.设置列表
list3 = [(i,j,k) for i in range(1,10,10) for j in range(10) for k in range(10)]
print(list3)
