# 可变参数：**kwargs
fn5 = lambda **kwargs: kwargs
print(fn5(name='python'))

print(fn5(name='Python', age=30))
