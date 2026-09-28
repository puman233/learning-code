# getcwd()  返回当前文件所在目录路径
import os

print(os.getcwd())

# chdir()   改变默认目录
# os.mkdir('aa')
# 需求：再aa文件夹里创建bb文件夹
# os.chdir('aa')
# os.mkdir('bb')

# listdir() 获取目录列表
# 获取某个文件夹下面所有文件，返回一个列表
print(os.listdir())
print(os.listdir('aa'))


