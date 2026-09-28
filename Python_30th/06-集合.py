
# 创建空集合
# 语法
st = set()

# 创建一个包含初始项目的集合
# 语法
st = {'item1', 'item2', 'item3', 'item4'}

# 示例
# 语法
fruits = {'banana', 'orange', 'mango', 'lemon'}
print(fruits)     # {'banana', 'orange', 'mango', 'lemon'}

# 获取设置的长度
# 我们使用len()方法来查找集合的长度。
st = {'item1', 'item2', 'item3', 'item4'}
len(st)
print(len(st))     # 4
fruits = {'banana', 'orange', 'mango', 'lemon'}
len(fruits)
print(len(fruits))     # 4
print()

# 检查项目
# 要检查列表中是否存在某个项目，我们使用 in 成员运算符。

fruits = {'香蕉', '橙色', '芒果', '柠檬'}
 
print('芒果' in fruits ) # True
print('苹果' in fruits ) # False
print()


# 向集合中添加元素
# 一旦集合创建后，我们不能改变其中的任何元素，但可以添加其他的元素

# 使用 add() 方法添加单个元素
fruits = {'banana', 'orange', 'mango', 'lemon'}
fruits.add('lime')
print(fruits)     # {'banana', 'orange', 'mango', 'lemon', 'lime'}

# 使用 update() 方法添加多个元素
# update() 方法允许向集合中添加多个元素。
# update() 接收一个列表作为参数.
fruits = {'banana', 'orange', 'mango', 'lemon'}
vegetables = ('tomato', 'potato', 'cabbage','onion', 'carrot')
fruits.update(vegetables)
print(fruits)     # {'banana', 'orange', 'mango', 'lemon', 'lime', 'tomato', 'potato', 'cabbage', 'onion', 'carrot'}
print()

# 从集合中移除元素
# 我们可以使用 remove() 方法从集合中移除一个元素。
# 如果找不到该元素，remove() 方法会抛出错误，
# 因此最好先检查该元素是否存在于集合中。
# discard() 方法则不会抛出任何错误。
fruits = {'banana', 'orange', 'mango', 'lemon'}
# fruits.pop()  # 从集合中移除一个随机元素
removed_item = fruits.pop()
print(removed_item)     # 随机移除一个元素
print(fruits)

fruits.discard('banana')  # 从集合中移除一个元素
print(fruits)
print()

# 如果我们想要清空或清除集合中的所有项目，可以使用 clear 方法。\
fruits = {'banana', 'orange', 'mango', 'lemon'}
fruits.clear()
print(fruits) # set()

# 删除一个集合
# 如果我们想要删除整个集合，可以使用 del 操作符。
st = {'item1', 'item2', 'item3', 'item4'}
del st

# 将列表转换为集合
# 我们可以将列表转换为集合，也可以将集合转换为列表。
# 将列表转换为集合会去除重复项，只保留唯一项。
fruits = ['banana', 'orange', 'mango', 'lemon','orange', 'banana']
fruits = set(fruits) # {'mango', 'lemon', 'banana', 'orange'}
print(fruits)

# 合并集合
# 我们可以使用 union() 或 update() 方法来合并两个集合。

# Union
# 这个方法返回一个新集合
fruits = {'banana', 'orange', 'mango', 'lemon'}
vegetables = {'tomato', 'potato', 'cabbage','onion', 'carrot'}
print(fruits.union(vegetables)) # {'lemon', 'carrot', 'tomato', 'banana', 'mango', 'orange', 'cabbage', 'potato', 'onion'}

# Update
# 这个方法将一个集合插入到给定的集合中
fruits = {'banana', 'orange', 'mango', 'lemon'}
vegetables = {'tomato', 'potato', 'cabbage','onion', 'carrot'}
fruits.update(vegetables)
print(fruits) # {'lemon', 'carrot', 'tomato', 'banana', 'mango', 'orange', 'cabbage', 'potato', 'onion'}
print()

# 查找交集项
# 交集返回两个集合中都存在的项的集合。
whole_numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
even_numbers = {0, 2, 4, 6, 8, 10}
print(whole_numbers.intersection(even_numbers)) # {0, 2, 4, 6, 8, 10}
 
python = {'p', 'y', 't', 'h', 'o', 'n'}
dragon = {'d', 'r', 'a', 'g', 'o', 'n'}
print(python.intersection(dragon))     # {'o', 'n'}
print()

"""
检查子集和超集
一个集合可以是另一个集合的子集或超集：

子集: issubset()
超集: issuperset()
"""
whole_numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
even_numbers = {0, 2, 4, 6, 8, 10}
print(whole_numbers.issubset(even_numbers)) # 错误，因为它是超集
print(whole_numbers.issuperset(even_numbers)) # 正确
 
python = {'p', 'y', 't', 'h', 'o', 'n'}
dragon = {'d', 'r', 'a', 'g', 'o', 'n'}
print(python.issubset(dragon))     # 错误
print()

# 检查两个集合之间的差异
# 它返回两个集合之间的差异
whole_numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
even_numbers = {0, 2, 4, 6, 8, 10}
print(whole_numbers.difference(even_numbers)) # {1, 3, 5, 7, 9}
 
python = {'p', 'y', 't', 'o', 'n'}
dragon = {'d', 'r', 'a', 'g', 'o', 'n'}
print(python.difference(dragon))     # {'p', 'y', 't'}  - 结果是无序的（集合的特性）
print(dragon.difference(python))     # {'d', 'r', 'a', 'g'}
print()


"""
查找两个集合之间的对称差异
它返回两个集合之间的对称差异。
它意味着它返回一个包含两个集合中所有项的集合，
除了同时出现在两个集合中的项，数学上：(A\B) ∪ (B\A)
"""
# 语法
st1 = {'item1', 'item2', 'item3', 'item4'}
st2 = {'item2', 'item3'}
# 意思是 (A\B)∪(B\A)
st2.symmetric_difference(st1) # {'item1', 'item4'}

whole_numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
some_numbers = {1, 2, 3, 4, 5}
print(whole_numbers.symmetric_difference(some_numbers)) # {0, 6, 7, 8, 9, 10}
 
python = {'p', 'y', 't', 'h', 'o', 'n'}
dragon = {'d', 'r', 'a', 'g', 'o', 'n'}
print(python.symmetric_difference(dragon))  # {'r', 't', 'p', 'y', 'g', 'a', 'd', 'h'}
print()

"""
合并集合
如果两个集合没有共同的项或项，我们称它们为不相交集合。
我们可以使用 isdisjoint() 方法来检查两个集合是否相交。
"""
# 语法
st1 = {'item1', 'item2', 'item3', 'item4'}
st2 = {'item2', 'item3'}
st2.isdisjoint(st1) # 错误

even_numbers = {0, 2, 4, 6, 8}
odd_numbers = {1, 3, 5, 7, 9}
print(even_numbers.isdisjoint(odd_numbers)) # 正确，因为没有共同项
 
python = {'p', 'y', 't', 'h', 'o', 'n'}
dragon = {'d', 'r', 'a', 'g', 'o', 'n'}
print(python.isdisjoint(dragon))  # 错误，有共同项 {'o', 'n'}



