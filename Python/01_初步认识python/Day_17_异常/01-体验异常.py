"""
当检测到一个错误时，解释器就无法继续执行了，反而出现了一些错误的提示，这就是所谓的“异常”

异常的写法：
    try:
        可能发生错误的代码

    except:
        如果出现异常执行的代码

"""

try:
    f = open('text.txt', 'r')
except:
    print("Error: Could not open")

try:
    f = open('1.txt', 'r')
except:
    f = open('text.txt', 'w')

