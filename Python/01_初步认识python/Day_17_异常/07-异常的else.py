# else 表示如果没有异常要执行的代码

try:
    open("01-体验异常.py", 'r').close()
except Exception as e:
    print(str(e))
else:
    print("Good")

try:
    open("02-体验异常.py", 'r').close()
except Exception as a:
    print(str(a))

try:
    open("03-体验异常.py", 'r').close()
except Exception as c:
    print(str(c))
else:
    print("Good")

try:
    open("04-体验异常.py", 'r')
except Exception as e:
    print(str(e))
