"""
    运算符         描述          支持的容器类型
    +             合并           字符串、列表、元组
    *             复制           字符串、列表、元组
    in          元素是否存在      字符串、列表、元组、字典
    not in      元素是否不存在     字符串、列表、元组、字典
"""
str1 = 'aa'
str2 = 'bb'

list1 = [1,2]
list2 = [10,20]

t1 = (1,2)
t2 = (10,20)

dict1 = {'name':'Python'}
dict2 = {'age':30}

# +
print(str1 + str2)
print(list1 + list2)
print(t1 + t2)

print("-" * 5 + "分割线" + '-' * 5)

# 乘号
str_new = 'a'
list_new = ['hello']
t_new = ('world',)

print(str_new * 5)

print('-' * 10)

print(list_new * 5)

print(t_new * 5)

print("-" * 5 + "分割线" + '-' * 5)

# 判断数据是否存在
str_python = 'abcd'
list_python = [10,20,30,40]
t_python = {100,200,300,400}
dict_new = {'name': 'Python','age':30}

print('a' in str_python)
print('a' not in str_python)

print(10 in list_python)
print(10 not in list_python)

print(100 not in t_python)
print(100 in t_python)

print('name' in dict_new)
print('name' not in dict_new)
print('name' in dict_new.keys())
print('name' in dict_new.values())
