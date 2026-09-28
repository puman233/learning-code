"""
字典是一种由无序、可修改（可变）的键值对组成的数据类型。
"""

# 创建字典
# 为了创建字典，我们使用大括号 {} 或内置函数 dict()。

# 语法
empty_dict = {}
# 带数据值的字典
dct = {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}

person = {
    'first_name':'Asabeneh',
    'last_name':'Yetayeh',
    'age':250,
    'country':'Finland',
    'is_married':True,
    'skills':['JavaScript', 'React', 'Node', 'MongoDB', 'Python'],
    'address':{
        'street':'Space street',
        'zipcode':'02210'
    }
    }
print(person, end="\n\n")

# 字典长度
# 它检查字典中的键值对的数量。

# 语法
dct = {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}
print(len(dct), end='\n\n') # 4

print('len(person) = ', len(person), end='\n\n')


# 访问字典项
# 我们可以通过参考其键名来访问字典项。

# 语法
dct = {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}
print(dct['key1']) # value1
print(dct['key4']) # value4
print()

print(person['first_name']) # Asabeneh
print(person['country'])    # Finland
print(person['skills'])     # ['JavaScript', 'React', 'Node', 'MongoDB', 'Python']
print(person['skills'][0])  # JavaScript
print(person['address']['street']) # Space street
# print(person['city'])       # 错误
print()


'''
通过键名访问项时，如果键不存在会引发错误。
为了避免这个错误，我们首先要检查键是否存在，
或者使用 get 方法。
get 方法在键不存在时返回 None
（这是 NoneType 对象数据类型)
'''

print(person.get('first_name')) # Asabeneh
print(person.get('country'))    # Finland
print(person.get('skills')) #['HTML','CSS','JavaScript', 'React', 'Node', 'MongoDB', 'Python']
print(person.get('city'))   # None
print()

# 向字典添加项
# 我们可以向字典中添加新的键值对

# 语法
dct = {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}
dct['key5'] = 'value5'

person['job_title'] = 'Insturctor'
person['skills'].append('HTML')
print(person)
print()

# 修改字典中的项目
# 我们可以修改字典中的项目

# 语法
dct = {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}
dct['key1'] = 'value-one'

person['first_name'] = 'Eyob'
person['age'] = 252
print(person)
print()

# 检查字典中的键
# 我们使用 in 运算符来检查字典中是否存在某个键

# 语法
dct = {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}
print('key2' in dct) # True
print('key5' in dct) # False

# 从字典中删除键值对
# pop(key): 删除具有指定键名的项目
# popitem(): 删除最后一个项目
# del: 删除具有指定键名的项目
# 语法
dct = {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}
dct.pop('key1') # 删除 key1 项目
dct = {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}
dct.popitem() # 删除最后一项
del dct['key2'] # 删除 key2 项目

person.pop('first_name')  # 删除 firstname 项目
person.popitem()          # 删除 address 项目
del person['is_married']  # 删除 is_married 项目
print(person)
print()


# 将字典改变为项目列表
# items() 方法将字典变成由元组组成的列表。

# 语法
dct = {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}
print(dct.items()) # dict_items([('key1', 'value1'), ('key2', 'value2'), ('key3', 'value3'), ('key4', 'value4')])


# 清空字典
# 如果我们不需要字典中的项目，
# 我们可以使用 clear() 方法来清空它们

# 语法
dct = {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}
print(dct.clear()) # None


# 删除字典
# 如果我们不再使用字典，我们可以完全删除它

# 语法
dct = {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}
del dct


# 复制字典
# 我们可以使用 copy() 方法复制一个字典。
# 使用 copy 方法可以避免原始字典被修改。

# 语法
dct = {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}
dct_copy = dct.copy() # {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}


# 获取字典的键列表
# keys() 方法给我们一个包含所有字典键的列表。

# 语法
dct = {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}
keys = dct.keys()
print(keys) # dict_keys(['key1', 'key2', 'key3', 'key4'])


# 获取字典的值列表
# values 方法给我们一个包含所有字典值的列表。

# 语法
dct = {'key1':'value1', 'key2':'value2', 'key3':'value3', 'key4':'value4'}
values = dct.values()
print(values) # dict_values(['value1', 'value2', 'value3', 'value4'])


