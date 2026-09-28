# finally表示无论是否异常都要执行的代码

try:
    open(filename, 'r').close()
except Exception as e:
    print(str(e))
else:
    print("File already exists.")
finally:
    print("File deleted")

