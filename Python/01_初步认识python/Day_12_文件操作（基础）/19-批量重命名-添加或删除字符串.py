"""
需求：批量修改文件名，即可添加指定字符串，又能删除指定字符串
"""
# 1.找到所有文件：获取当前文件夹的目录列表
import os

# 构造条件的数据
flag = 2

file_list = os.listdir()
print(file_list)

# 2.构造名字
for i in file_list:
    if flag == 1:
        new_name = 'Python_' + i
    elif flag == 2:
        num = len('Python_')
        new_name = i[num:]
    # 3.重命名
    os.rename(i, new_name)

