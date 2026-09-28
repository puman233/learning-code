"""
    认识字符串
·字符串类型：
    - 一对引号字符串
    - 三引号字符串
"""
# Eg:
# 单引号
a = 'hello world'
print(a)
print(type(a))

# 双引号
b = "Hello World"
print(b)
print(type(b))

# 三引号
c = """Good morning!"""
print(c)
print(type(c))
c_2 = """
        Good morning!
        teacher!
        """
print(c_2)
print(type(c_2))


# 单引号的注意事项：
# 打印： I'm Tom
hello = "I'm Tom"
print(hello)
print(type(hello))
hello_2 = ('I\''
           'm Tom')
print(hello_2)
print(type(hello_2))

hello_3 = ('I\n'
           '\'' # 包含一个单引号字符 的字符串（转义）
           '\n'
          'm Tom')
print(hello_3)