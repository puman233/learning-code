"""
    需求：
        创建一个字典，字典key是1~5数字，value是这个数字的2次方
"""

# 1. 创建字典   key 是 1~5 的数字，v是这个数字的平方
dict1 = {i: i**2 for i in range(1,5)}
print(dict1)

dict2 = {k**3 for k in range(1,9)}
print(dict2)
