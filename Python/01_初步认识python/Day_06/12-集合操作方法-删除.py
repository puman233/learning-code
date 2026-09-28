"""
    remove():   删除集合中的指定数据，如果数据不存在则报错

    discard():  删除集合中的指定数据，如果数据不存在也不会报错

    pop():  随即删除集合中的数据，并返回此数据
"""


s1 = {10,20,30,40,50}

# remove()
# s1.remove(10)
# print(s1)

# discard()
s1.discard(10)
print(s1)


# pop()
print(s1.pop())
print(s1)