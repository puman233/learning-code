import collections
import os
import sys

"""
    目标：
        应用：学员管理系统
        递归
        lambda表达式
        高阶函数
"""


def restart_program():
    """重启函数"""
    python = sys.executable
    os.execl(python, python, *sys.argv)


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
    # 1.用户输入：学号、姓名、手机号、成绩、性别、班级
    new_id = input("请输入学号：")
    new_name = input("请输入姓名：")
    new_tel = input("请输入手机号：")
    new_gender = input("请输入性别：")
    new_grade = input("请输入成绩：")
    new_classroom = input("请输入班级：")

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
    info_dict['grade'] = new_grade
    info_dict['gender'] = new_gender
    info_dict['classroom'] = new_classroom

    # 列表追加字典
    info.append(info_dict)
    print("添加成功！")


# 删除学员函数
def del_info():
    """删除函数"""
    global info
    # 1.用户输入要删除的学院的姓名
    print("首先，让我知道您想删除哪一位学员")
    del_key = input("请输入你要删除的学员的 id 学号；name 姓名；tel 手机号 ：")
    del_key_str = del_key.lower()
    if del_key_str == "name":
        del_name = input("请输入要删除的学员的姓名：")
        # 2.判断学员是否存在：存在则删除，不存在则提：
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
    elif del_key_str == 'id':
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
    elif del_key_str == 'tel':
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

    def judgment_modify():
        print("您可以修改：id 学号；name 姓名；tel 电话号码；class 班级；gender 性别；grade 成绩")
        judgment_key = str(input(f"你想要修改 {i['id']} {i['name']} 的什么？"))
        judgment_key_str = judgment_key.lower()
        if judgment_key_str == 'id':
            i['id'] = input("请修改此学员的学号：")
            print("修改成功！")
        elif judgment_key_str == 'name':
            i['name'] = input("请修改此学员的姓名：")
        elif judgment_key_str == 'tel':
            i['tel'] = input("请修改此学员的电话号码：")
        elif judgment_key_str == 'class':
            i['classroom'] = input("请修改此学员的班级：")
        elif judgment_key_str == 'gender':
            i['gender'] = input("请修改此学员的性别：")
        elif judgment_key_str == 'grade':
            i['grade'] = input("请修改此学员的成绩：")
        else:
            print("您的输入有误！")
            print("再次尝试……")
            restart_program()

    # 1.用户输入想要修改的学员的姓名
    print("首先，我们想要知道你想要修改哪一位学员的信息")
    modify_key = str(input("请输入你要修改的学员的 id 学号；name 姓名；tel 手机号 ："))
    modify_key_str = modify_key.lower()
    if modify_key_str == "name":
        modify_name = input("请修改的学员的姓名：")
        # 2.判断学员是否存在：存在则修改
        # 不存在则提示
        # 2.1 遍历列表，判断输入的姓名
        for i in info:
            if modify_name == i['name']:
                judgment_modify()
                break
        else:
            print("该学员不存在！")
    elif modify_key_str == 'id':
        modify_id = input("请输入要修改的学员的学号：")
        # 4.遍历列表
        for i in info:
            # 5.判断学员是否存在：（列表里边的字典）
            if modify_id == i['id']:
                judgment_modify()
                print("修改成功！")
                break
        else:
            print("该学员不存在！")
    elif modify_key_str == 'tel':
        modify_tel = input("请输入要修改的学员的手机号：")
        # 2.判断学员是否存在：不存在则提示
        # 4.遍历列表
        for i in info:
            # 5.判断学员是否存在：存在则执行删除（列表里边的字典）
            if modify_tel == i['tel']:
                judgment_modify()
                print("修改成功！")
                break
        else:
            print("该学员不存在！")


# 查询学员函数
def search_info():
    """查询学员信息"""
    global info
    # 1.用户输入目标学院姓名
    print("首先，让我们知道你想查询哪一位学员的信息")
    search_key = str(input("请输入你要查询学员的方法——id 学号；name 姓名；tel 手机号 ："))
    search_key_str = search_key.lower()
    if search_key_str == "name":
        search_name = input("请您输入要查询的学员的姓名：")
        # 2.判断学员是否存在：
        # 不存在则提示
        # 2.1 遍历列表，判断输入的姓名
        for i in info:
            if search_name == i['name']:
                print("查询到的学员信息如下：")
                print(
                    f"学员的学号是{i['id']}，姓名是{i['name']}，手机号是{i['tel']}，性别是{i['gender']}，成绩是{i['grade']}，班级是{i['classroom']}")
                break
        else:
            print("该学员不存在！")
    elif search_key_str == 'id':
        search_id = input("请您输入要查询的学员的学号：")
        # 2.判断学员是否存在：
        # 不存在则提示
        # 2.1 遍历列表，判断输入的姓名
        for i in info:
            if search_id == i['id']:
                print("查询到的学员信息如下：")
                print(
                    f"学员的学号是{i['id']}，姓名是{i['name']}，手机号是{i['tel']}，性别是{i['gender']}，成绩是{i['grade']}，班级是{i['classroom']}")
                break
        else:
            print("该学员不存在！")
    elif search_key_str == 'tel':
        search_tel = input("请输入要查询的学员的手机号：")
        # 4.遍历列表
        for i in info:
            # 5.判断学员是否存在：存在则执行（列表里边的字典）
            if search_tel == i['tel']:
                print("查询到的学员信息如下：")
                print(
                    f"学员的学号是{i['id']}，姓名是{i['name']}，手机号是{i['tel']}，性别是{i['gender']}，成绩是{i['grade']}，班级是{i['classroom']}")
                break
        else:
            print("该学员不存在！")


# 显示所有学员函数
def print_all():
    """显示所有"""
    # 1.打印提示字
    print("学员\t\t姓名\t\t手机号\t\t性别\t\t成绩\t\t班级")
    # 2.打印所有学员的数据
    for i in info:
        print(f"{i['id']}\t\t{i['name']}\t\t{i['tel']}\t\t{i['gender']}\t\t{i['grade']}\t\t{i['classroom']}")


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
            exit_flag = str(input("确定要退出吗？ YES 或 NO :"))
            exit_flag_str = exit_flag.lower()
            if exit_flag_str == 'yes':
                print("即将为您退出系统")
                break
            elif exit_flag_str == 'no':
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
    print("  ")
    print("  ")
