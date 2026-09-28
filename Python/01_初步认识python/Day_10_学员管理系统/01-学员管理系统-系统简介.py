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
    elif user_num == 2:
        print("删除")
    elif user_num == 3:
        print("修改")
    elif user_num == 4:
        print("查询")
    elif user_num == 5:
        print("显示所有")
    elif user_num == 6:
        print("退出系统")
        exit(0)
