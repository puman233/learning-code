"""
不定长参数也叫可变参数
用于不确定调用的时候会传递多少个参数（不传递也可以）
此时，可以用包裹(packing)位置参数，或者包裹关键字参数，来进行参数传递，会显得十分方便

注意：
    传进的所有参数都会被args变量收集，它会根据传进参数的位置合并成为一个元祖(tuple)
    args是元组类型，这就是包裹位置传递
"""


# 用包裹位置传递
def user_info(*args):
    print(args)


user_info('Tom')
user_info('Tom', 18)
user_info()

print("-" * 50)

"""
注意：
    无论是包裹位置传递还是包裹关键字传递
    都是一个组包的过程    
"""


# 包裹关键字传递
def user_info_2(**kwargs):
    print(kwargs)


user_info_2(name='Tom', age=18, id=110)
