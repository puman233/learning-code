# 1.用户输入目标文件
old_name = input("请输入你想要备份的文件名：")
# print(old_name)
# print(type(old_name))

# 2.规划备份文件的名字
# 2.1 提取后缀 - 找到名字中的英文符号“点” - 名字后后缀分离
# 最右侧的点才是后缀的点 -- 字符串查找某个字串 rfind
index = old_name.rfind('.')
# print(index)

# 4.思考：有效文件才备份
if index > 0:
    # 提取后缀
    postfix = old_name[index:]

# 2.2 组织新名字 = 原名字 + [备份] + 后缀
# 原名字就是字符串的一部分 - 切片 [开始:结束:步长]
# print(old_name[:index])
# print(old_name[index:])
# new_name = old_name[:index] + "【备份】" + old_name[index:]
new_name = old_name[:index] + "【备份】" + postfix
print(new_name)

# 3.给份文件写入数据（数据和源文件一样）

# 3.1 打开 源文件 和 备份文件
old_f = open(old_name, 'rb')
new_f = open(new_name, 'wb')

# 3.2 原文件读取，备份文件写入
while True:
    con = old_f.read(1024)
    if len(con) == 0:
        # 表示读取完成
        break
    new_f.write(con)
# 3.3 关闭文件
old_f.close()
new_f.close()
