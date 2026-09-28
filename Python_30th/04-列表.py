
"""
列表

Python 中有四种集合数据类型：

- List：有序且可变的集合。允许重复的成员。
- Tuple：有序且不可变的集合。允许重复的成员。
- Set：无序、不可索引且不可变的集合，但我们可以向集合中添加新项。不允许重复的成员。
- Dictionary：无序、可变且可索引的集合。不允许重复的成员。

列表是不同数据类型的集合，有序且可修改（可变）。列表可以为空，也可以包含不同数据类型的项。
"""

# - 使用内置函数 list()

# 语法
from traceback import print_tb


lst = list()

empty_list = list()
print(empty_list)  # 输出: []


# 使用方括号，[]

# 语法
lst = []

empty_list = [] # 这是一个空列表
print(len(empty_list)) # 0
print()


fruits = ['banana', 'orange', 'mango', 'lemon']                     # list of fruits
vegetables = ['Tomato', 'Potato', 'Cabbage','Onion', 'Carrot']      # list of vegetables
animal_products = ['milk', 'meat', 'butter', 'yoghurt']             # list of animal products
web_techs = ['HTML', 'CSS', 'JS', 'React','Redux', 'Node', 'MongDB'] # list of web technologies
countries = ['Finland', 'Estonia', 'Denmark', 'Sweden', 'Norway']

# 打印列表及其长度
print('Fruits:', fruits)
print('Number of fruits:', len(fruits))
print('Vegetables:', vegetables)
print('Number of vegetables:', len(vegetables))
print('Animal products:',animal_products)
print('Number of animal products:', len(animal_products))
print('Web technologies:', web_techs)
print('Number of web technologies:', len(web_techs))
print('Countries:', countries)
print('Number of countries:', len(countries))
print()



# 列表可以包含不同数据类型的项

lst = ['Asabeneh', 250, True, {'country':'Finland', 'city':'Helsinki'}] # 包含不同数据类型的列表
print(lst)
print()


# 使用负索引访问列表项
# 负索引意味着从末尾开始，-1 指的是最后一项，-2 指的是倒数第二项。

fruits = ['banana', 'orange', 'mango', 'lemon']
first_fruit = fruits[-4]
last_fruit = fruits[-1]
second_last = fruits[-2]
print(first_fruit)      # banana
print(last_fruit)       # lemon
print(second_last)      # mango
print()


# 拆解列表项

lst = ['item1','item2','item3', 'item4', 'item5']
first_item, second_item, third_item, *rest = lst
print(first_item)     # item1
print(second_item)    # item2
print(third_item)     # item3
print(rest)           # ['item4', 'item5']

# 示例一
fruits = ['banana', 'orange', 'mango', 'lemon','lime','apple']
first_fruit, second_fruit, third_fruit, *rest = fruits 
print(first_fruit)     # banana
print(second_fruit)    # orange
print(third_fruit)     # mango
print(rest)           # ['lemon','lime','apple']
# 示例二
first, second, third,*rest, tenth = [1,2,3,4,5,6,7,8,9,10]
print(first)          # 1
print(second)         # 2
print(third)          # 3
print(rest)           # [4,5,6,7,8,9]
print(tenth)          # 10
# 示例三
countries = ['Germany', 'France','Belgium','Sweden','Denmark','Finland','Norway','Iceland','Estonia']
gr, fr, bg, sw, *scandic, es = countries
print(gr)           # Germany
print(fr)           # France
print(bg)           # Belgium
print(sw)           # Sweden
print(scandic)      # ['Denmark', 'Finland', 'Norway', 'Iceland']
print(es)           # Estonia

print()


# 列表切分

# 正索引：我们可以通过指定开始、结束和步长来指定一系列正索引，
# 返回值将是一个新列表。 
# （开始默认值为 0，结束默认值为 len(lst) - 1（最后一项），步长默认值为 1）

fruits = ['banana', 'orange', 'mango', 'lemon']
all_fruits = fruits[0:4] # 返回所有项

#与上面返回值相同
all_fruits = fruits[0:] # 如果不指定结束索引，将返回从开始到最后一项的所有项
orange_and_mango = fruits[1:3] # 不包含第一项
orange_mango_lemon = fruits[1:]
orange_and_lemon = fruits[::2] # 我们使用了第三个参数，步长。 每两项取一条 - ['banana', 'mango']

# 负索引：我们可以通过指定开始、结束和步长来指定一系列负索引，
# 返回值将是一个新列表。

fruits = ['banana', 'orange', 'mango', 'lemon']
all_fruits = fruits[-4:] # 返回所有项
orange_and_mango = fruits[-3:-1] # 不包含最后一项，['orange', 'mango']
orange_mango_lemon = fruits[-3:] # 返回从-3到末尾的项，['orange', 'mango', 'lemon']
reverse_fruits = fruits[::-1] # 负步长将按相反顺序排列列表,['lemon', 'mango', 'orange', 'banana']
print()


# 修改列表
# 列表是一个可变或可修改的有序集合。下面我们修改 fruit 列表。

fruits = ['banana', 'orange', 'mango', 'lemon']
fruits[0] = 'avocado'
print(fruits)       #  ['avocado', 'orange', 'mango', 'lemon']
fruits[1] = 'apple'
print(fruits)       #  ['avocado', 'apple', 'mango', 'lemon']
last_index = len(fruits) - 1
fruits[last_index] = 'lime'
print(fruits)        #  ['avocado', 'apple', 'mango', 'lime']
print()

# 检索列表项
# 使用 in 运算符检查列表项是否为列表的成员。请参阅下面的示例。

fruits = ['banana', 'orange', 'mango', 'lemon']
does_exist = 'banana' in fruits
print(does_exist)  # True
does_exist = 'lime' in fruits
print(does_exist)  # False
print()

# 添加列表项
# 要将项添加到现有列表的末尾，我们使用 append() 方法。

# 语法
# lst = list()
# lst.append(item)

fruits = ['banana', 'orange', 'mango', 'lemon']
fruits.append('apple')
print(fruits)           # ['banana', 'orange', 'mango', 'lemon', 'apple']
fruits.append('lime')   # ['banana', 'orange', 'mango', 'lemon', 'apple', 'lime']
print(fruits)
print()

# 插入列表项
# 我们可以使用 insert() 方法在列表中的指定索引处插入单个项。请注意，其他项将向右移动。insert() 方法接受两个参数：索引和要插入的项。

# 语法
# lst = ['item1', 'item2']
# lst.insert(index, item)

fruits = ['banana', 'orange', 'mango', 'lemon']
fruits.insert(2, 'apple') # 在 orange 。 mango 中插入 apple
print(fruits)           # ['banana', 'orange', 'apple', 'mango', 'lemon']
fruits.insert(3, 'lime')   # ['banana', 'orange', 'apple', 'lime', 'mango', 'lemon']
print(fruits)
print()

# 移除列表项
# 使用 remove() 方法从列表中删除指定的项

# 语法
# lst = ['item1', 'item2']
# lst.remove(item)

fruits = ['banana', 'orange', 'mango', 'lemon', 'banana']
fruits.remove('banana')
print(fruits)  # ['orange', 'mango', 'lemon', 'banana'] - 此方法删除列表中第一次出现的项
fruits.remove('lemon')
print(fruits)  # ['orange', 'mango', 'banana']
print()


# 使用 Pop 删除列表项
# 使用 pop() 方法删除指定索引（如果未指定索引，则删除最后一项）：

# 语法
# lst = ['item1', 'item2']
# lst.pop()       # 最后一项
# lst.pop(index)

fruits = ['banana', 'orange', 'mango', 'lemon']
fruits.pop()
print(fruits)       # ['banana', 'orange', 'mango']

fruits.pop(0)
print(fruits)       # ['orange', 'mango']
print()


# 使用 Del 删除列表项
# 使用 del 关键字删除指定索引，也可以用于删除索引范围内的项。它还可以完全删除列表

# 语法
# lst = ['item1', 'item2']
# del lst[index] # 只删除一项
# del lst        # 删除整个列表

fruits = ['banana', 'orange', 'mango', 'lemon', 'kiwi', 'lime']
del fruits[0]
print(fruits)       # ['orange', 'mango', 'lemon', 'kiwi', 'lime']
del fruits[1]
print(fruits)       # ['orange', 'lemon', 'kiwi', 'lime']
del fruits[1:3]     # 这将删除给定索引之间的项，因此不会删除索引为 3 的项!
print(fruits)       # ['orange', 'lime']
del fruits
# print(fruits)       # 这里会提示: NameError: name 'fruits' is not defined
print()


# 列表复制
# 可以通过将其重新分配给新变量来复制列表: list2 = list1。
# 现在，list2 是 list1 的引用，
# 我们对 list2 进行的任何更改也将修改原始的 list1。
# 但是有很多时候我们不想修改原始的列表，而是想要一个不同的副本。
# 为了避免这个问题，我们使用 copy()。

# 语法
# lst = ['item1', 'item2']
# lst_copy = lst.copy()

fruits = ['banana', 'orange', 'mango', 'lemon']
fruits_copy = fruits.copy()
print(fruits_copy)       # ['banana', 'orange', 'mango', 'lemon']
print()


# 连接列表
# 有几种方法可以连接或连接两个或多个列表。
#     加号 (+)

# 语法
# list3 = list1 + list2

positive_numbers = [1, 2, 3, 4, 5]
zero = [0]
negative_numbers = [-5,-4,-3,-2,-1]
integers = negative_numbers + zero + positive_numbers
print(integers) # [-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5]
fruits = ['banana', 'orange', 'mango', 'lemon']
vegetables = ['Tomato', 'Potato', 'Cabbage', 'Onion', 'Carrot']
fruits_and_vegetables = fruits + vegetables
print(fruits_and_vegetables ) # ['banana', 'orange', 'mango', 'lemon', 'Tomato', 'Potato', 'Cabbage', 'Onion', 'Carrot']
print()


# 使用 extend() 方法 extend() 方法可以将列表附加到列表中。请参阅下面的示例。

# 语法
# list1 = ['item1', 'item2']
# list2 = ['item3', 'item4', 'item5']
# list1.extend(list2)

num1 = [0, 1, 2, 3]
num2= [4, 5, 6]
num1.extend(num2)
print('Numbers:', num1) # Numbers: [0, 1, 2, 3, 4, 5, 6]
negative_numbers = [-5,-4,-3,-2,-1]
positive_numbers = [1, 2, 3,4,5]
zero = [0]

negative_numbers.extend(zero)
negative_numbers.extend(positive_numbers)
print('Integers:', negative_numbers) # Integers: [-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5]
fruits = ['banana', 'orange', 'mango', 'lemon']
vegetables = ['Tomato', 'Potato', 'Cabbage', 'Onion', 'Carrot']
fruits.extend(vegetables)
print('Fruits and vegetables:', fruits ) # Fruits and vegetables: ['banana', 'orange', 'mango', 'lemon', 'Tomato', 'Potato', 'Cabbage', 'Onion', 'Carrot']
print()


# 统计列表项
# 使用 count() 方法返回列表中指定项出现的次数:

# 语法
# lst = ['item1', 'item2']
# lst.count(item)

fruits = ['banana', 'orange', 'mango', 'lemon']
print(fruits.count('orange'))   # 1
ages = [22, 19, 24, 25, 26, 24, 25, 24]
print(ages.count(24))           # 3


# 查找项的索引
# index() 方法返回列表中项的索引:

# 语法
# lst = ['item1', 'item2']
# lst.index(item)

fruits = ['banana', 'orange', 'mango', 'lemon']
print(fruits.index('orange'))   # 1
ages = [22, 19, 24, 25, 26, 24, 25, 24]
print(ages.index(24))           # 2， 第一次出现
print()


# 列表反转
# 使用 reverse() 方法反转列表的顺序。

# 语法
# lst = ['item1', 'item2']
# lst.reverse()

fruits = ['banana', 'orange', 'mango', 'lemon']
fruits.reverse()
print(fruits) # ['lemon', 'mango', 'orange', 'banana']
ages = [22, 19, 24, 25, 26, 24, 25, 24]
ages.reverse()
print(ages) # [24, 25, 24, 26, 25, 24, 19, 22]
print()


# 列表排序
# 要对列表进行排序，我们可以使用 sort() 方法或内置函数 sorted()。
# sort() 方法将列表项按升序重新排序并修改原始列表。
# 如果 sort() 方法的 reverse 参数为 true，则会按降序排列列表。

# sort(): 这个方法会修改原始列表

# 语法
lst = ['item1', 'item2']
lst.sort()                # ascending
lst.sort(reverse=True)    # descending

# 示例：

fruits = ['banana', 'orange', 'mango', 'lemon']
fruits.sort()
print(fruits)             # 按字母排序， ['banana', 'lemon', 'mango', 'orange']
fruits.sort(reverse=True)
print(fruits) # ['orange', 'mango', 'lemon', 'banana']
ages = [22, 19, 24, 25, 26, 24, 25, 24]
ages.sort()
print(ages) #  [19, 22, 24, 24, 24, 25, 25, 26]

ages.sort(reverse=True)
print(ages) #  [26, 25, 25, 24, 24, 24, 22, 19]
print()

# sorted(): 不会修改原始列表，而是返回一个新列表
# 示例:

fruits = ['banana', 'orange', 'mango', 'lemon']
print(sorted(fruits))   # ['banana', 'lemon', 'mango', 'orange']
# Reverse order
fruits = ['banana', 'orange', 'mango', 'lemon']
fruits = sorted(fruits,reverse=True)
print(fruits)     # ['orange', 'mango', 'lemon', 'banana']

for i in sorted(fruits):
    print(i)











