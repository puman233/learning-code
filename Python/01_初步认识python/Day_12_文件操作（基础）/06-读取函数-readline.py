"""
readline()一次读取一行内容
"""

f = open('test.txt', 'r')

com = f.readline()
print(com)
com = f.readline()
print(com)

f.close()
