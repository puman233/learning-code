"""
    key值查找写法
        注意：查找的key值存在，返回值，否则报错

    get()查找写法
        语法：
            字典序列.get(key,默认值)
        注意：如果当前查找的key不存在则返回第二个参数（默认值），如果省略第二个参数，则返回None
"""

dict1 = {'name':'Tom','age':20,'gender':'男'}

# [key]
print(dict1['name'])
# print(dict1['names']) # 报错

# get()
dict2 = {'name':'Tom','age':20,'gender':'男'}
print(dict2.get('name'))
# dict2.get('name')

# keys()
dict3 = {'name':'Tom','age':20,'gender':'男'}
print(dict3.keys())

# values()
dict4 = {'name':'Tom','age':20,'gender':'男'}
print(dict4.values())

# item()
dict5 = {'name':'Tom','age':20,'gender':'男'}
print(dict5.items())
