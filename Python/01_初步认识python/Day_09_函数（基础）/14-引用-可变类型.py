"""
    引用：可变类型
"""

# 列表
aa =  [10,20]
bb = aa

print(bb)

# aa和bb的值是一样的
print(id(aa))
print(id(bb))

aa.append(30)
print(aa)
print(bb)   # 列表是可变类型

print(id(aa))
print(id(bb))



