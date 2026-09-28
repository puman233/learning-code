"""
    目标：
        应用：学员管理系统
        递归
        lambda表达式
        高阶函数
"""

# 等待存储所有学员的信息
info = []


# 添加学员函数
def add_info():
    """添加学员函数"""
    # 1.用户输入：学号、姓名、手机号
    new_id = input("请输入学号：")
    new_name = input("请输入姓名：")
    new_tel = input("请输入手机号：")

    # 2.判断是否添加此学员
    # 如果已存在，错误提示；否则添加数据
    global info
    # 2.1 不允许姓名重复
    # 判断用户输入的姓名 和 列表里的字典的name对应的值 相等 则提示
    for i in info:
        if new_name == i['name']:
            print("该用户已存在！")
            # return 退出当前函数
            return 0

    # 2.2 如果输入的姓名不存在，添加数据
    # 准备空字典，字典新增数据，列表追加字典
    info_dict = {}

    # 字典新增数据
    info_dict['id'] = new_id
    info_dict['name'] = new_name
    info_dict['tel'] = new_tel

    # 列表追加字典
    info.append(info_dict)
    print(info)


# 删除学员函数
def del_info():
    """删除函数"""
    # 1.用户输入要删除的学院的姓名
    del_name = input("请输入要删除的学员的姓名：")

    # 2.判断学员是否存在：存在则删除，不存在则提示
    # 3.声明info是全局变量
    global info
    # 4.遍历列表
    for i in info:
        # 5.判断学员是否存在：存在则执行删除（列表里边的字典）
        if del_name == i['name']:
            # 列表删除数据 ——按数据删除remove
            info.remove(i)
            print("删除成功！")
            # break：这个系统不允许重名，删除了一个后面的不需要再遍历
            break
    else:
        print("该学员不存在！")


# 定义功能界面函数
def info_print():
    print("请选择功能" + "-" * 10)
    print("1.添加学员")
    print("2.删除学员")
    print("3.修改学员")
    print("4.查询学员")
    print("5.显示所有学员")
    print("6.退出系统")


# 系统功能需要循环使用，指导用户输入6，才退出系统
while True:
    # 1.显示功能界面
    info_print()

    # 2.用户输入功能序号
    user_num = int(input("请输入功能序号："))

    # 3.按照用户输入的功能序号，执行不同的功能
    # 如果用户输入1，执行添加，如果用户输入2，执行删除。以此类推
    if user_num == 1:
        print("添加")
        add_info()
    elif user_num == 2:
        print("删除")
        del_info()
    elif user_num == 3:
        print("修改")
    elif user_num == 4:
        print("查询")
    elif user_num == 5:
        print("显示所有")
    elif user_num == 6:
        print("退出系统")
        exit(0)
    else:
        print("输入的功能序号有误")
        print("重新启动……")
    print("  " * 10)
    print("  " * 10)
