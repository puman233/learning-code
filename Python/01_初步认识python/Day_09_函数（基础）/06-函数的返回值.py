# 需求：一个函数有两个返回值：1和2

# 一个函数如果有多个return不能都执行，只执行第一个return
# 无法做到一个函数返回多个返回值
# def return_num():
#     return 1
#     return 2

def return_num():
    return 1,2  # 返回的是元组


result = return_num()
print(result)

"""
    return a,b写法，返回多个数据的时候，默认是元组类型
    return后面可以连接列表、元组或字典，已返回多个值
"""


def return_result():
    return {'name':'Python','age':30}


result_2 = return_result()
print(result_2)


