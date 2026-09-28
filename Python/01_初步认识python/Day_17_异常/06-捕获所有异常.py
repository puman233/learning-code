# Exception是所有程序异常类的父类

try:
    print(num)
except Exception as e:
    print(e)

try:
    open(filename, 'r')
except Exception as e:
    print(e)

