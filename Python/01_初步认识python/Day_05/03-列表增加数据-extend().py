"""
    extend():   列表结尾追加数据，如果数据是一个序列，则将这个序列的数据逐一添加到列表
    语法：
        列表序列.extend(数据)
"""
name_list = ['Tom','Amy','Lily']

# name_list.extend('Xiaoming')
name_list.extend(['xiaoming','xiaohong'])

print(name_list)

