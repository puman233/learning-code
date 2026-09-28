"""
    修改

    所谓修改字符串，指的是通过函数的形式修改字符串中的数据

    - replace():    替换
        1.语法：
            字符串序列.replace(旧子串,新子串,替换次数)

    - join():   用一个字符或字符串合并成字符串，
                就是将多个字符串合并成为一个新的字符串
        1.语法:
            字符或字符串.join(多字符串组成的序列)
"""
# 创建变量
mystr = "Hello world and Python can do well"
# replace() 把and换成my
new_str = mystr.replace('and','my')
print(mystr)
print(new_str)

# 调用了replace函数后，原有字符串的数据并没有做到修改，
# 修改后的数据是replace函数的返回值
# 说明了字符串是不可变数据类型
# 数据是否可以改变划分为 可变类型 和不可变类型

def data_replace():
    hello = 'I am Tom, I have a good time.'
    new_hello = hello.replace('Tom','Sam')
    print(hello)
    print(new_hello)

"""
    join
        元素之间插入字符串
"""

myjoin = ['aa','bb','cc']
# aa...bb...cc
new_join = '...'.join(myjoin)
print(new_join)



"""
    split():    按照指定字符串分割字符串
        1.语法：
            字符串序列.split(分割字符,maxsplit)
"""
And = "Tom and Sam and Sandy and Andy and Amy and Bob and Candy"
new_and = And.split('and')
print(new_and)
new_or = And.split('and',2)
print(new_or)
