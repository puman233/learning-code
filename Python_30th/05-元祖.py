
"""

元组

元组是有序且不可变的不同数据类型的集合。
一旦创建了元组，我们就无法更改其值。
我们不能在元组中使用 add、insert、remove 方法，因为它是不可修改的（不可变的）。
与列表不同，元组的方法很少。

与元组相关的方法有：
    tuple()：创建一个空元组
    count()：计算元组中指定项的数量
    index()：查找元组中指定项的索引
    + 运算符：连接两个或多个元组并创建一个新元组

"""


# 创建一个空元组
# 语法
empty_tuple = ()
# 或使用元组构造函数
empty_tuple = tuple()


# 创建一个具有初始值的元组
# 语法
tpl = ('item1', 'item2','item3')

fruits = ('banana', 'orange', 'mango', 'lemon')


# 我们使用 len() 方法来获取元组的长度。
# 语法
tpl = ('item1', 'item2', 'item3')
len(tpl)


# 正索引与列表数据类型类似，
# 我们使用正索引或负索引来访问元组项。

# 语法
tpl = ('item1', 'item2', 'item3')
first_item = tpl[0]
second_item = tpl[1]

fruits = ('banana', 'orange', 'mango', 'lemon')
first_fruit = fruits[0]
second_fruit = fruits[1]
last_index = len(fruits) - 1
last_fruit = fruits[last_index]

# 负索引负索引是从末尾开始的，
# -1 表示最后一项，-2 表示倒数第二项，
# 列表/元组长度的负数表示第一项。 

# 语法
tpl = ('item1', 'item2', 'item3','item4')
first_item = tpl[-4]
second_item = tpl[-3]

fruits = ('banana', 'orange', 'mango', 'lemon')
first_fruit = fruits[-4]
second_fruit = fruits[-3]
last_fruit = fruits[-1]
print()


# 我们可以通过指定开始和结束的索引范围来切出子元组，
# 返回值是一个包含指定项的新元组。

# 正索引范围
# 语法
tpl = ('item1', 'item2', 'item3','item4')
all_items = tpl[0:4]         # 所有项
all_items = tpl[0:]         # 所有项
middle_two_items = tpl[1:3]  # 不包括索引 3 的项

fruits = ('banana', 'orange', 'mango', 'lemon')
all_fruits = fruits[0:4]    # 所有项
all_fruits= fruits[0:]      # 所有项
orange_mango = fruits[1:3]  # 不包括索引 3 的项
orange_to_the_rest = fruits[1:]
print(all_items)
print(orange_mango)
print(orange_to_the_rest)
print()

# 负索引范围
# 语法
tpl = ('item1', 'item2', 'item3','item4')
all_items = tpl[-4:]         # 所有项
middle_two_items = tpl[-3:-1]  # 不包括索引 3 的项

fruits = ('banana', 'orange', 'mango', 'lemon')
all_fruits = fruits[-4:]    # 所有项
orange_mango = fruits[-3:-1]  # 不包括索引 3 的项
orange_to_the_rest = fruits[-3:]
print(all_items)
print(orange_mango)
print(orange_to_the_rest)
print()


# 将元组更改为列表
# 我们可以将元组更改为列表，将列表更改为元组。
# 如果我们想修改元组，我们应该将其更改为列表。

# 语法
tpl = ('item1', 'item2', 'item3','item4')
lst = list(tpl)

fruits = ('banana', 'orange', 'mango', 'lemon')
fruits = list(fruits)
fruits[0] = 'apple'
print(fruits)     # ['apple', 'orange', 'mango', 'lemon']
fruits = tuple(fruits)
print(fruits)     # ('apple', 'orange', 'mango', 'lemon')


# 检索元组中的项
# 我们可以使用 in 检查元组中是否存在某个项，
# 它返回一个布尔值。

# 语法
tpl = ('item1', 'item2', 'item3','item4')
'item2' in tpl # True

fruits = ('banana', 'orange', 'mango', 'lemon')
print('orange' in fruits) # True
print('apple' in fruits) # False
# fruits[0] = 'apple' # TypeError: 'tuple' object does not support item assignment


# 连接元组
# 我们可以使用 + 运算符连接两个或多个元组

# 语法
tpl1 = ('item1', 'item2', 'item3')
tpl2 = ('item4', 'item5','item6')
tpl3 = tpl1 + tpl2

fruits = ('banana', 'orange', 'mango', 'lemon')
vegetables = ('Tomato', 'Potato', 'Cabbage','Onion', 'Carrot')
fruits_and_vegetables = fruits + vegetables
print(fruits_and_vegetables) # ('banana', 'orange', 'mango', 'lemon', 'Tomato', 'Potato', 'Cabbage', 'Onion', 'Carrot')
print()

# 删除元组
# 不能删除元组中的单个项，但可以使用 del 删除元组本身。

# 语法
tpl1 = ('item1', 'item2', 'item3')
del tpl1

fruits = ('banana', 'orange', 'mango', 'lemon')
del fruits
# print(fruits) # NameError: name 'fruits' is not defined
print()


