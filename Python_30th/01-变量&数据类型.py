
# Python 变量名规则

# 变量名必须以字母或下划线字符开头
# 变量名不能以数字开头
# 变量名只能包含字母数字字符和下划线（A-z、0-9 和 _ ）
# 变量名区分大小写（firstname、Firstname、FirstName 和 FIRSTNAME 是不同的变量）

# Python 开发人员使用蛇形命名法 (snake_case) 变量命名约定。
# 对于包含多个单词的变量，我们在每个单词后使用下划线
# （例如 first_name、last_name、engine_rotation_speed）

# Python 中的变量
first_name = 'Asabeneh'
last_name = 'Yetayeh'
country = 'Finland'
city = 'Helsinki'
age = 250
is_married = True
skills = ['HTML', 'CSS', 'JS', 'React', 'Python']
person_info = {
   'firstname':'Asabeneh',
   'lastname':'Yetayeh',
   'country':'Finland',
   'city':'Helsinki'
   }


print('Hello, World!') # The text Hello, World! is an argument
print('Hello',',', 'World','!') # it can take multiple arguments, four arguments have been passed
print(len('Hello, World!')) # it takes only one argument

print()

# 打印变量的值

print('First name:', first_name)
print('First name length:', len(first_name))
print('Last name: ', last_name)
print('Last name length: ', len(last_name))
print('Country: ', country)
print('City: ', city)
print('Age: ', age)
print('Married: ', is_married)
print('Skills: ', skills)
print('Person information: ', person_info)

print()
# 在一行中声明多个变量
first_name, last_name, country, age, is_married = 'Asabeneh', 'Yetayeh', 'Helsink', 250, True

print(first_name, last_name, country, age, is_married)
print('First name:', first_name)
print('Last name: ', last_name)
print('Country: ', country)
print('Age: ', age)
print('Married: ', is_married)

print()


# 使用内置函数 input() 获取用户输入

first_name = input('What is your name: ')
age = input('How old are you? ')

print(first_name)
print(age)

print()

# 数据类型

"""
数字
整数：它被认为是整数（负数、零和正数） 示例： ... -3, -2, -1, 0, 1, 2, 3 ...
浮点数：小数 示例： ... -3.5, -2.25, -1.0, 0.0, 1.1, 2.2, 3.5 ...
复数 示例： 1 + j, 2 + 4j

字符串
一串字符组成的文本，使用单引号或双引号表示。如果字符串超过一行，可以使用三引号。

例子:

'Asabeneh'
'Finland'
'Python'
'I love teaching'
'I hope you are enjoying the first day of 30DaysOfPython Challenge'
布尔值
布尔值是 True 或 False。T 和 F 必须大写。

例子:

True # 灯是开的吗？如果是开着的，那么值是 True
False # 灯是开的吗？如果是关着的，那么值是 False
列表
列表是一个有序的集合，可以存储不同类型的数据。类似于 JavaScript 中的数组。

例子:

[0, 1, 2, 3, 4, 5] # 所有都是相同数据类型 - 数字列表
['Banana', 'Orange', 'Mango', 'Avocado'] # 所有都是相同数据类型 - 字符串列表（水果）
['Finland','Estonia', 'Sweden','Norway'] # 所有都是相同数据类型 - 字符串列表（国家）
['Banana', 10, False, 9.81] # 列表中的不同数据类型 - 字符串、整数、布尔值和浮点数
字典
Python 字典对象是以键值对格式存储的无序集合。

例子:

{
'first_name':'Asabeneh',
'last_name':'Yetayeh',
'country':'Finland',
'age':250,
'is_married':True,
'skills':['JS', 'React', 'Node', 'Python']
}
元组
元组是一个有序的集合，类似于列表，但元组一旦创建就不能修改。它们是不可变的。

例子:

('Asabeneh', 'Pawel', 'Brook', 'Abraham', 'Lidiya') # 名字
('Earth', 'Jupiter', 'Neptune', 'Mars', 'Venus', 'Saturn', 'Uranus', 'Mercury') # 行星
集合
集合是类似于列表和元组的集合数据类型。与列表和元组不同，集合不是一个有序的集合。就像在数学中一样，Python 中的集合只存储唯一的项目。

在后面的部分，我们将详细介绍每种 Python 数据类型。

例子:

{2, 4, 3, 5}
{3.14, 9.81, 2.7} # 集合中的顺序不重要
"""


# Python 中有多种数据类型。为了识别数据类型，我们使用 type 内置函数。

# python 中不同的数据类型
# 声明一些有各种数据类型的变量

first_name = 'Asabeneh'     # str
last_name = 'Yetayeh'       # str
country = 'Finland'         # str
city= 'Helsinki'            # str
age = 250                   # int, 不用担心，这并不是我真实的年龄 :) 

# Printing out types
print(type('Asabeneh'))     # str 字符串
print(type(first_name))     # str 字符串
print(type(10))             # int 整数
print(type(3.14))           # float 浮点数
print(type(1 + 1j))         # complex 复数
print(type(True))           # bool 布尔值
print(type([1, 2, 3, 4]))     # list 列表
print(type({'name':'Asabeneh','age':250, 'is_married':250}))    # dict 字典
print(type((1,2)))                                              # tuple 元组
print(type(zip([1,2],[3,4])))                                   # set 集合

print()

# 数据类型转换：
# 将一种数据类型转换为另一种数据类型。
# 我们使用 int()、float()、str()、list、set 当我们进行算术运算时，
# 字符串数字应首先转换为 int 或 float，否则将返回错误。
# 如果我们将数字与字符串连接起来，则应首先将数字转换为字符串.

# 整型 到 浮点型
num_int = 10
print('num_int',num_int)         # 10
num_float = float(num_int)
print('num_float:', num_float)   # 10.0

# 浮点型 到 整型
gravity = 9.81
print(int(gravity))             # 9

# 整型 到 字符串
num_int = 10
print(num_int)                  # 10
num_str = str(num_int)
print(num_str)                  # '10'

# 字符串 到 整型或浮点型
num_str = '10.6'
"""
print('num_int', int(num_str))      # 10
print('num_float', float(num_str))  # 10.6
报错，因为 num_str 是一个浮点数的字符串，不能直接转换为整型
"""
print('num_float', int(float(num_str)))  # 10
print('num_float', float(num_str))  # 10.6

# 字符串 到 列表
first_name = 'Asabeneh'
print(first_name)               # 'Asabeneh'
first_name_to_list = list(first_name)
print(first_name_to_list)            # ['A', 's', 'a', 'b', 'e', 'n', 'e', 'h']


