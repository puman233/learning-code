
# 字符串
# 文本是一种字符串数据类型。
# 任何以文本形式书写的数据类型都是字符串。
# 任何用单引号、双引号或三引号括起来的数据都是字符串。
# 有很多方法和内置函数来处理字符串类型的数据。
# 使用 len() 方法获取字符串的长度。


letter = 'P'                # 字符串可以是一个字符，也可以是一堆文字
print(letter)               # P
print(len(letter))          # 1
greeting = 'Hello, World!'  # 字符串使用单引号或双引号构建，"Hello, World!"
print(greeting)             # Hello, World!
print(len(greeting))        # 13
sentence = "I hope you are enjoying 30 days of Python Challenge"
print(sentence)
print()

# 多行字符串使用三个单引号 (''') 或者三个双引号 (""") 创建

multiline_string = '''I am a teacher and enjoy teaching.
I didn't find anything as rewarding as empowering people.
That is why I created 30 days of python.'''
print(multiline_string)

# 换种方式
multiline_string = """I am a teacher and enjoy teaching.
I didn't find anything as rewarding as empowering people.
That is why I created 30 days of python."""
print(multiline_string)
print()

# 字符串串联
# 我们可以将字符串连接在一起。合并或连接字符串称为串联。

first_name = 'Asabeneh'
last_name = 'Yetayeh'
space = ' '
full_name = first_name  +  space + last_name
print(full_name) # Asabeneh Yetayeh
# 使用 len() 内置函数获取字符串的长度
print(len(first_name))  # 8
print(len(last_name))   # 7
print(len(first_name) > len(last_name)) # True
print(len(full_name)) # 16
print()


"""
字符串中的转译序列
在 Python 和其他编程语言中，\ 后跟一个字符是转义序列。
以下是一些常见的转义序列：
    \n: 换行
    \t: 制表符(4个空格)
    \\: 反斜杠
    \': 单引号
    \": 双引号

"""

print('I hope everyone is enjoying the Python Challenge.\nAre you ?') # 换行
print('Days\tTopics\tExercises') # 增加一个制表符
print('Day 1\t5\t5')
print('Day 2\t6\t20')
print('Day 3\t5\t23')
print('Day 4\t1\t35')
print('This is a backslash  symbol (\\)') # 输出反斜杠
print('In every programming language it starts with \"Hello, World!\"') # 在单引号里写双引号

# 输出
"""
I hope every one is enjoying the Python Challenge.
Are you ?
Days	Topics	Exercises
Day 1	5	    5
Day 2	6	    20
Day 3	5	    23
Day 4	1	    35
This is a backslash  symbol (\)
In every programming language it starts with "Hello, World!"
"""
print()
"""字符串格式化
传统风格字符串格式化 (% 操作符)
在 Python 中有许多格式化字符串的方法。

“%”运算符用于格式化包含在“元组”（固定大小列表）中的一组变量，以及格式字符串，
其中包含普通文本以及“参数说明符”、特殊符号如“%s”、“%d”、“%f”、“%.数字f”。

%s - 字符串 (或者任何可以用字符串表述的对象，例如数字)
%d - 整型
%f - 浮点型
"%.小数位数f" - 固定精度的浮点数

"""

# 仅字符串
first_name = 'Asabeneh'
last_name = 'Yetayeh'
language = 'Python'
formated_string = 'I am %s %s. I teach %s' %(first_name, last_name, language)
print(formated_string)

# 字符串和数字
radius = 10
pi = 3.14
area = pi * radius ** 2
formated_string = 'The area of circle with a radius %d is %.2f.' %(radius, area) # 2 表示小数点后的 2 位有效数字

python_libraries = ['Django', 'Flask', 'NumPy', 'Matplotlib','Pandas']
formated_string = 'The following are python libraries:%s' % (python_libraries)
print(formated_string) # 输出 "The following are python libraries:['Django', 'Flask', 'NumPy', 'Matplotlib','Pandas']"
print()


# 新式字符串格式化 (str.format)
# 这种格式化方式是在 Python 3 中引入的


first_name = 'Asabeneh'
last_name = 'Yetayeh'
language = 'Python'
formated_string = 'I am {} {}. I teach {}'.format(first_name, last_name, language)
print(formated_string)
a = 4
b = 3

print('{} + {} = {}'.format(a, b, a + b))
print('{} - {} = {}'.format(a, b, a - b))
print('{} * {} = {}'.format(a, b, a * b))
print('{} / {} = {:.2f}'.format(a, b, a / b)) # 限制保留两位小数
print('{} % {} = {}'.format(a, b, a % b))
print('{} // {} = {}'.format(a, b, a // b))
print('{} ** {} = {}'.format(a, b, a ** b))

# 输出
"""
4 + 3 = 7
4 - 3 = 1
4 * 3 = 12
4 / 3 = 1.33
4 % 3 = 1
4 // 3 = 1
4 ** 3 = 64
"""

# 字符串和数字
radius = 10
pi = 3.14
area = pi * radius ** 2
formated_string = 'The area of a circle with a radius {} is {:.2f}.'.format(radius, area) # 保留两位小数
print(formated_string)
print()


# 字符串插值 / f-Strings (Python 3.6+)
# 另一种新的字符串格式化是字符串插值，f-strings。
# 字符串以 f 开头，我们可以在相应的位置注入数据。

a = 4
b = 3
print(f'{a} + {b} = {a + b}')
print(f'{a} - {b} = {a - b}')
print(f'{a} * {b} = {a * b}')
print(f'{a} / {b} = {a / b:.2f}')
print(f'{a} % {b} = {a % b}')
print(f'{a} // {b} = {a // b}')
print(f'{a} ** {b} = {a ** b}')
print()


"""
Python 字符串是字符序列
与其他 Python 有序对象 - 列表和元组 - 共享基本访问方法
从字符串中提取单个字符的最简单方法是将它们解压缩到相应的变量中。
（以及从任何序列中提取单个成员的方法）

"""

# 拆解字符
language = 'Python'
a,b,c,d,e,f = language # 拆解字符串中的字符并赋值给变量
print(a) # P
print(b) # y
print(c) # t
print(d) # h
print(e) # o
print(f) # n
print()


"""
通过索引获取字符串中的字符
在编程中，计数从零开始。
因此，字符串的第一个字母位于零索引处，字符串的最后一个字母位于字符串长度减一处。
"""

language = 'Python'
first_letter = language[0]
print(first_letter) # P
second_letter = language[1]
print(second_letter) # y
last_index = len(language) - 1
last_letter = language[last_index]
print(last_letter) # n

# 如果我们想从右边开始，我们可以使用负索引。-1 是最后一个索引。
language = 'Python'
last_letter = language[-1]
print(last_letter) # n
second_last = language[-2]
print(second_last) # o

print()

# 字符串切片
# 在 Python 中，我们可以将字符串切片为子字符串。

language = 'Python'
first_three = language[0:3] # 从零索引开始，直到 3 但不包括 3
print(first_three) #Pyt
last_three = language[3:6]
print(last_three) # hon
# 另一种方式
last_three = language[-3:]
print(last_three)   # hon
last_three = language[3:]
print(last_three)   # hon
print()


# 字符串反转
# 我们可以轻松地反转字符串。

greeting = 'Hello, World!'
print(greeting[::-1]) # !dlroW ,olleH


# 切片时跳过字符
# 通过将步长参数传递给切片方法，可以在切片时跳过字符。

language = 'Python'
pto = language[0:6:2] #
print(pto) # Pto
print()


"""
    字符串方法
    
"""

# capitalize(): 将字符串中的第一个字符转换为大写字母
challenge = 'thirty days of python'
print(challenge.capitalize()) # 'Thirty days of python'
print()

# count(): 返回字符串中子字符串的出现次数，count(子字符串，start=..，end=..)。
# start 是计数的起始索引，end 是计数的最后一个索引。
challenge = 'thirty days of python'
print(challenge.count('y')) # 3
print(challenge.count('y', 7, 14)) # 1, 
print(challenge.count('th')) # 2`
print()

# endswith(): 判断字符串是否以特定的子字符串结尾，返回 True 或 False
challenge = 'thirty days of python'
print(challenge.endswith('on'))   # True
print(challenge.endswith('tion')) # False
print()

# expandtabs(): 用空格替换制表符，默认制表符大小为 8。它接受制表符大小参数
challenge = 'thirty\tdays\tof\tpython'
print(challenge.expandtabs())   # 'thirty  days    of      python'
print(challenge.expandtabs(10)) # 'thirty    days      of        python'
print()

# find(): 返回子字符串第一次出现的索引，如果未找到则返回 -1
challenge = 'thirty days of python'
print(challenge.find('y'))  # 5
print(challenge.find('th')) # 0
print()

# rfind(): 返回子字符串最后一次出现的索引，如果未找到则返回 -1
challenge = 'thirty days of python'
print(challenge.rfind('y'))  # 16
print(challenge.rfind('th')) # 17
print()

# format(): 将字符串格式化为更美观的输出
first_name = 'Asabeneh'
last_name = 'Yetayeh'
age = 250
job = 'teacher'
country = 'Finland'
sentence = 'I am {} {}. I am a {}. I am {} years old. I live in {}.'.format(first_name, last_name, age, job, country)
print(sentence) # I am Asabeneh Yetayeh. I am 250 years old. I am a teacher. I live in Finland.

radius = 10
pi = 3.14
area = pi * radius ** 2
result = 'The area of a circle with radius {} is {}'.format(str(radius), str(area))
print(result) # The area of a circle with radius 10 is 314
print()

# index(): 返回子字符串的最小索引，附加参数表示起始和结束索引
# （默认为 0，字符串长度为 - 1）。
# 如果未找到子字符串，则会引发 valueError。
challenge = 'thirty days of python'
sub_string = 'da'
print(challenge.index(sub_string))  # 7
# print(challenge.index(sub_string, 9)) # error
print()

# rindex(): 返回子字符串的最大索引，附加参数表示起始和结束索引
# （默认为 0，字符串长度为 - 1）。
challenge = 'thirty days of python'
sub_string = 'da'
print(challenge.rindex(sub_string))  # 8
# print(challenge.rindex(sub_string, 9)) # error
print()

# isalnum(): 判断字符串字符是否都是字母数字字符
challenge = 'ThirtyDaysPython'
print(challenge.isalnum()) # True

challenge = '30DaysPython'
print(challenge.isalnum()) # True

challenge = 'thirty days of python'
print(challenge.isalnum()) # False, 空格不是字母字符

challenge = 'thirty days of python 2019'
print(challenge.isalnum()) # False
print()

# isalpha(): 判断字符串字符是否都是字母字符 (a-z and A-Z)
challenge = 'thirty days of python'
print(challenge.isalpha()) # False, 空格不是字母字符
challenge = 'ThirtyDaysPython'
print(challenge.isalpha()) # True
num = '123'
print(num.isalpha())      # False
print()

# isdecimal(): 判断符串中的所有字符是否都是十进制 (0-9)
challenge = 'thirty days of python'
print(challenge.isdecimal())  # False
challenge = '123'
print(challenge.isdecimal())  # True
challenge = '\u00B2'
print(challenge.isdigit())   # False
challenge = '12 3'
print(challenge.isdecimal())  # False, 含有空格
print()

# isdigit(): 判断字符串中的所有字符是否都是数字
# （0-9 和一些其他表示数字的 Unicode 字符）
challenge = 'Thirty'
print(challenge.isdigit()) # False
challenge = '30'
print(challenge.isdigit())   # True
challenge = '\u00B2'
print(challenge.isdigit())   # True
print()

# isnumeric(): 判断字符串中的所有字符是否都是数字或与数字相关
# （就像 isdigit()，只是接受更多符号，如 ½）
num = '10'
print(num.isnumeric()) # True
num = '\u00BD' # ½
print(num.isnumeric()) # True
num = '10.5'
print(num.isnumeric()) # False
print()

# isidentifier(): 判断有效的标识符 - 检查字符串是否是有效的变量名
challenge = '30DaysOfPython'
print(challenge.isidentifier()) # False, 因为以数字开头
challenge = 'thirty_days_of_python'
print(challenge.isidentifier()) # True
print()

# islower(): 判断字符串中的所有字母是否都是小写
challenge = 'thirty days of python'
print(challenge.islower()) # True
challenge = 'Thirty days of python'
print(challenge.islower()) # False
print()

# isupper(): 判断字符串中的所有字母是否都是大写
challenge = 'thirty days of python'
print(challenge.isupper()) #  False
challenge = 'THIRTY DAYS OF PYTHON'
print(challenge.isupper()) # True
print()

# join(): 返回连接后的字符串
web_tech = ['HTML', 'CSS', 'JavaScript', 'React']
result = ' '.join(web_tech)
print(result) # 'HTML CSS JavaScript React'
web_tech = ['HTML', 'CSS', 'JavaScript', 'React']
result = '# '.join(web_tech)
print(result) # 'HTML# CSS# JavaScript# React'
print()

# strip(): 删除字符串开头和结尾的所有给定字符
challenge = 'thirty days of pythoonnn'
print(challenge.strip('noth')) # 'irty days of py'
print()

# replace(): 用给定的字符串替换子字符串
challenge = 'thirty days of python'
print(challenge.replace('python', 'coding')) # 'thirty days of coding'
print()

# split(): 使用给定的字符串或空格作为分隔符来拆分字符串
challenge = 'thirty days of python'
print(challenge.split()) # ['thirty', 'days', 'of', 'python']
challenge = 'thirty, days, of, python'
print(challenge.split(', ')) # ['thirty', 'days', 'of', 'python']
print()

# title(): 返回标题大小写的字符串
challenge = 'thirty days of python'
print(challenge.title()) # Thirty Days Of Python
print()

# swapcase(): 将所有大写字符转换为小写字符，将所有小写字符转换为大写字符
challenge = 'thirty days of python'
print(challenge.swapcase())   # THIRTY DAYS OF PYTHON
challenge = 'Thirty Days Of Python'
print(challenge.swapcase())  # tHIRTY dAYS oF pYTHON
print()

# startswith(): 判断字符串是否以指定字符串开头
challenge = 'thirty days of python'
print(challenge.startswith('thirty')) # True
print()

challenge = '30 days of python'
print(challenge.startswith('thirty')) # False

print()


