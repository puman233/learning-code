"""
    拆包：字典
"""

dict1 = {'name':'Tom','age':20}
# dict1中有两个键值对，拆包的时候用两个变量接收数据
a,b = dict1
print(a)
print(b)

# 获取v值
print(dict1[a])
print(dict1[b])

