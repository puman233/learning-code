"""
readlines 可以按照行的方式把整个文件中的内容进行一次性的读取，并且返回的是一个列表
其中每一行的数据为一个元素
"""

f = open('test.txt', 'r')

con = f.readlines()
print(con)

f.close()

