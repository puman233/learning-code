"""
    add()

    update()
"""
s1 = {10,20}

# add()     只增加单个数据
s1.add(100)
print(s1)

s1.add(100) # 集合有去重复功能，如果追加的数据是集合已有数据，则什么数据都不做
print(s1)

# s1.add(100,200,300) # 报错
# print(s1)

# update()  # 增加的数据是序列
s1.update([10,20,30,40,50])
print(s1)
