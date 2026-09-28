dict1 = {'name':'Tom','age':20,'gender':'男'}

# del 删除字典或指定的键值对
del(dict1)
# print(dict1)    # 报错即生效

dict2 = {'name':'Tom','age':20,'gender':'男'}
del dict2['name']
print(dict2)

# clear()      清空字典
dict3 = {'name':'Tom','age':20,'gender':'男'}
dict3.clear()
print(dict3)




