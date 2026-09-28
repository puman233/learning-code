
"""
Boolean
布尔类型表示两个值之一：True 或 False。
一旦我们开始使用比较运算符，这些数据类型的使用将变得清晰。
第一个字母 T 表示 True，F 表示 False

与 JavaScript 不同，Python 的布尔类型的首字母应该是大写。
"""
# 示例: 布尔类型的值

print(True)
print(False)

print()

"""
算术运算符：
加(+)： a + b
减(-)： a - b
乘(*)： a * b
除(/)： a / b
模运算(%)： a % b
整除(//)： a // b
指数运算(**)： a ** b

"""

# Python 中的算术运算符
# 整型

print('加法: ', 1 + 2)      # 3
print('减法: ', 2 - 1)      # 1
print('乘法: ', 2 * 3)      # 6
print('除法: ', 4 / 2)      # 2.0  Python 中的除法运算符返回浮点数
print('除法: ', 6 / 2)      # 3.0         
print('除法: ', 7 / 2)      # 3.5
print('整除: ', 7 // 2)     # 3,  返回商的整数部分
print('整除: ', 7 // 3)     # 2
print('取模: ', 3 % 2)      # 1, 返回余数
print('指数运算: ', 2 ** 3) # 8 代表 2 * 2 * 2

# 浮点数
print('浮点数, 圆周率', 3.14)
print('浮点数, 重力加速度', 9.81)

# 复数
print('复数: ', 1 + 1j)
print('复数相乘: ',(1 + 1j) * (1 - 1j))

print()

# 首先声明变量

a = 3 # a 是一个变量名，3 是一个整型值
b = 2 # b 是一个变量名，2 是一个整型值

# 进行算术运算，并将结果赋值给变量
total = a + b
diff = a - b
product = a * b
division = a / b
remainder = a % b
floor_division = a // b
exponential = a ** b

# 应该使用 sum 而不是 total，但 sum 是一个内置函数 - 尽量避免覆盖内置函数
print(total) # 如果不打印标签字符串，就不知道值是怎么计算出来的
print('a + b = ', total)
print('a - b = ', diff)
print('a * b = ', product)
print('a / b = ', division)
print('a % b = ', remainder)
print('a // b = ', floor_division)
print('a ** b = ', exponential)

print()

print('== 加法、减法、乘法、除法、取模 ==')

# 声明变量，并把声明语句放在一起
num_one = 3
num_two = 4

# 算术运算
total = num_one + num_two
diff = num_two - num_one
product = num_one * num_two
div = num_two / num_one
remainder = num_two % num_one

# 使用标签打印值
print('总和: ', total)
print('差: ', diff)
print('乘积: ', product)
print('商: ', div)
print('余数: ', remainder)

print()

# 计算圆的面积
radius = 10                                 # 圆的半径
area_of_circle = 3.14 * radius ** 2         # 两个 * 符号表示指数或幂
print('圆的面积:', area_of_circle)

# 计算矩形面积
length = 10
width = 20
area_of_rectangle = length * width
print('矩形的面积:', area_of_rectangle)

# 计算物体重量
mass = 75
gravity = 9.81
weight = mass * gravity
print(weight, 'N')                         # 为重量添加单位

# 计算液体密度
mass = 75 # 单位是 Kg
volume = 0.075 # 单位是 m³
density = mass / volume # 1000 Kg/m³
print(density, 'Kg/m³') # 为密度添加单位

print()

"""
比较运算符
在编程中，我们使用比较运算符来比较两个值。
我们检查一个值是否大于或小于或等于另一个值
"""

print(3 > 2)     # True, 因为3大于2
print(3 >= 2)    # True, 因为3大于2
print(3 < 2)     # False,  因为3大于2
print(2 < 3)     # True, 因为2小于3
print(2 <= 3)    # True, 因为2小于3
print(3 == 2)    # False, 因为3不等于2
print(3 != 2)    # True, 因为3不等于2
print(len('mango') == len('avocado'))  # False
print(len('mango') != len('avocado'))  # True
print(len('mango') < len('avocado'))   # True
print(len('milk') != len('meat'))      # False
print(len('milk') == len('meat'))      # True
print(len('tomato') == len('potato'))  # True
print(len('python') > len('dragon'))   # False


# 比较得到 True 或者 False

print('True == True: ', True == True)
print('True == False: ', True == False)
print('False == False:', False == False)

"""
除了上述比较运算符之外，Python 还使用：

is: 如果变量相等，返回 True(x is y)
is not: 如果变量不相等，返回 True(x is not y)
in: 如果列表包含某变量，返回 True(x in y)
not in: 如果列表不包含某变量(x in y)
"""

print('1 is 1', 1 is 1)                   # True - 因为值相等
print('1 is not 2', 1 is not 2)           # True - 因为值不相等
print('A in Asabeneh', 'A' in 'Asabeneh') # True - 字符串中含有元素 A
print('B in Asabeneh', 'B' in 'Asabeneh') # False - 没有大写字母 B
print('coding' in 'coding for all') # True - 因为 coding 都在 'coding for all' 中
print('a in an:', 'a' in 'an')      # True
print('4 is 2 ** 2:', 4 is 2 ** 2)   # True

# 逻辑运算符
# 不像其他的编程语言，Python 使用关键字 和、或 和 not 作为逻辑运算符。

print(3 > 2 and 4 > 3) # True - 因为两个语句都是 True
print(3 > 2 and 4 < 3) # False - 因为其中一个语句是 False
print(3 < 2 and 4 < 3) # False - 因为两个语句都是 False
print('True and True: ', True and True)
print(3 > 2 or 4 > 3)  # True - 因为两个语句都是 True
print(3 > 2 or 4 < 3)  # True - 因为其中一个语句是 True
print(3 < 2 or 4 < 3)  # False - 因为两个语句都是 False
print('True or False:', True or False)
print(not 3 > 2)     # False - 因为 3 > 2 是 True,  not True 得到 False
print(not True)      # False - not 运算符把 True 改为 False
print(not False)     # True
print(not not True)  # True
print(not not False) # False




