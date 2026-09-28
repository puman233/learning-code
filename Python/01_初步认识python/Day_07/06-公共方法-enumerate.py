"""
    enumerate() 函数用于将一个可便利的数据对象（如列表、元组或字符串）组合为一个索引序列，同时列出数据和数据下表，一般用于for循环中
"""

list1 = ['a','b','c','d','e']

for a in enumerate(list1):
    print(a)

print("-" * 20)

# 注意：start=1 是确定开始数字为1。其中默认为0
for c in enumerate(list1,start=1):
    print(c)
