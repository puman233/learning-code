"""
    目标：
        应用：学员管理系统
        递归
        lambda表达式
        高阶函数
"""


# 定义功能界面函数
def info_print():
    print("请选择功能" + "-" * 10)
    print("1.添加学员")
    print("2.删除学员")
    print("3.修改学员")
    print("4.查询学员")
    print("5.显示所有学员")
    print("6.退出系统")


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
        if new_name == i['name'] or new_id == i['id'] or new_tel == i['tel']:
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
    print("添加成功！")


# 删除学员函数
def del_info():
    """删除函数"""
    global info
    # 1.用户输入要删除的学院的姓名
    del_key = input("请输入你要删除学员的方法——id 学号；name 姓名；tel 手机号 ：")
    if del_key == "name" or del_key == "Name" or del_key == "NAME":
        del_name = input("请输入要删除的学员的姓名：")
        # 2.判断学员是否存在：存在则删除，不存在则提示
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
    elif del_key == 'id' or del_key == 'ID' or del_key == 'iD' or del_key == 'Id':
        del_id = input("请输入要删除的学员的学号：")
        # 2.判断学员是否存在：存在则删除，不存在则提示
        # 4.遍历列表
        for i in info:
            # 5.判断学员是否存在：存在则执行删除（列表里边的字典）
            if del_id == i['id']:
                # 列表删除数据 ——按数据删除remove
                info.remove(i)
                print("删除成功！")
                # break：这个系统不允许重名，删除了一个后面的不需要再遍历
                break
        else:
            print("该学员不存在！")
    elif del_key == 'tel' or del_key == 'Tel' or del_key == 'TEL' or del_key == 'TEl' or del_key == 'TeL':
        del_tel = input("请输入要删除的学员的手机号：")
        # 2.判断学员是否存在：存在则删除，不存在则提示
        # 4.遍历列表
        for i in info:
            # 5.判断学员是否存在：存在则执行删除（列表里边的字典）
            if del_tel == i['tel']:
                # 列表删除数据 ——按数据删除remove
                info.remove(i)
                print("删除成功！")
                # break：这个系统不允许重名，删除了一个后面的不需要再遍历
                break
        else:
            print("该学员不存在！")


# 修改函数
def modify_info():
    """修改学员信息"""
    global info
    # 1.用户输入想要修改的学员的姓名
    modify_key = input("请输入你要修改学员的方法——id 学号；name 姓名；tel 手机号 ：")
    if modify_key == "name" or modify_key == "Name" or modify_key == "NAME":
        modify_name = input("请您输入想要修改的学员的姓名：")
        # 2.判断学员是否存在：存在则修改
        # 不存在则提示
        # 2.1 遍历列表，判断输入的姓名
        for i in info:
            if modify_name == i['name']:
                # 修改 将修改tel这个值
                i['name'] = input("请修改此学员的名字：")
                print("修改成功！")
                break
        else:
            print("该学员不存在！")
    elif modify_key == 'id' or modify_key == 'ID' or modify_key == 'iD' or modify_key == 'Id':
        modify_id = input("请输入要修改的学员的学号：")
        # 2.判断学员是否存在：存在则删除，不存在则提示
        # 4.遍历列表
        for i in info:
            # 5.判断学员是否存在：（列表里边的字典）
            if modify_id == i['id']:
                info.remove(i)
                print("修改成功！")
                # break：这个系统不允许重名，删除了一个后面的不需要再遍历
                break
        else:
            print("该学员不存在！")
    elif modify_key == 'tel' or modify_key == 'Tel' or modify_key == 'TEL' or modify_key == 'TEl' or modify_key == 'TeL':
        modify_tel = input("请输入要修改的学员的手机号：")
        # 2.判断学员是否存在：不存在则提示
        # 4.遍历列表
        for i in info:
            # 5.判断学员是否存在：存在则执行删除（列表里边的字典）
            if modify_tel == i['tel']:
                # 列表删除数据 ——按数据删除remove
                info.remove(i)
                print("修改成功！")
                # break：这个系统不允许重名，删除了一个后面的不需要再遍历
                break
        else:
            print("该学员不存在！")


# 查询学员函数
def search_info():
    """查询学员信息"""
    global info
    # 1.用户输入目标学院姓名
    search_key = input("请输入你要查询学员的方法——id 学号；name 姓名；tel 手机号 ：")
    if search_key == "name" or search_key == "Name" or search_key == "NAME":
        search_name = input("请您输入要查询的学员的姓名：")
        # 2.判断学员是否存在：
        # 不存在则提示
        # 2.1 遍历列表，判断输入的姓名
        for i in info:
            if search_name == i['name']:
                print("查询到的学员信息如下：")
                print(f"学员的学号是{i['id']}，姓名是{i['name']}，手机号是{i['tel']}")
                break
        else:
            print("该学员不存在！")
    elif search_key == 'id' or search_key == 'ID' or search_key == 'iD' or search_key == 'Id':
        search_id = input("请您输入要查询的学员的学号：")
        # 2.判断学员是否存在：
        # 不存在则提示
        # 2.1 遍历列表，判断输入的姓名
        for i in info:
            if search_id == i['id']:
                print("查询到的学员信息如下：")
                print(f"学员的学号是{i['id']}，姓名是{i['name']}，手机号是{i['tel']}")
                break
        else:
            print("该学员不存在！")
    elif search_key == 'tel' or search_key == 'Tel' or search_key == 'TEL' or search_key == 'TEl' or search_key == 'TeL':
        search_tel = input("请输入要查询的学员的手机号：")
        # 4.遍历列表
        for i in info:
            # 5.判断学员是否存在：存在则执行（列表里边的字典）
            if search_tel == i['tel']:
                print("查询到的学员信息如下：")
                print(f"学员的学号是{i['id']}，姓名是{i['name']}，手机号是{i['tel']}")
                break
        else:
            print("该学员不存在！")


# 显示所有学员函数
def print_all():
    """显示所有"""
    # 1.打印提示字
    print("学员\t\t姓名\t\t手机号")
    # 2.打印所有学员的数据
    for i in info:
        print(f"{i['id']}\t{i['name']}\t{i['tel']}")


# 系统功能需要循环使用，指导用户输入6，才退出系统
while True:
    # 1.显示功能界面
    info_print()

    # 2.用户输入功能序号
    user_num = int(input("请输入功能序号："))

    # 3.按照用户输入的功能序号，执行不同的功能
    # 如果用户输入1，执行添加，如果用户输入2，执行删除。以此类推
    if type(user_num) == int:
        user_num_int = int(user_num)
        if user_num_int == 1:
            print("添加")
            add_info()
        elif user_num_int == 2:
            print("删除")
            del_info()
        elif user_num_int == 3:
            print("修改")
            modify_info()
        elif user_num_int == 4:
            print("查询")
            search_info()
        elif user_num_int == 5:
            print("显示所有")
            print_all()
        elif user_num_int == 6:
            print("退出系统")
            exit_flag = input("确定要退出吗？ YES 或 NO :")
            if exit_flag == 'yes' or exit_flag == 'Yes' or exit_flag == 'YEs' or exit_flag == 'YES':
                print("即将为您退出系统")
                break
            elif exit_flag == 'NO' or exit_flag == 'No' or exit_flag == 'no':
                print("继续运行系统")
                print(" ")
                continue
        else:
            print("输入的功能序号有误")
            print("继续运行系统……")
            continue
    else:
        print("您的输入有误！")
        print("即将继续运行系统……")
        continue
    print("  " * 10)
    print("  " * 10)
