"""
    账号管理系统V2.11.088

    新版本特性：
        · 功能更新！
            - 新增 主窗口 程序入口
            - 新增 学生 & 教师 权限
            - 新增 管理员 最高级权限
            - 优化体验
        · 版本更新！
            - 重构代码
            - 重构多种表达式
"""

person_name_list = []  # 定义列表，用于储存用户名、年龄


def start_window():
    print("-------------------------------------------------")
    print("*                                               *")
    print("*             账号管理系统 V2.11.088              *")
    print("*                                               *")
    print("-------------------------------------------------")


def Main_exit():
    over = int(input("您真的要退出此程序吗？请输入序号 4 (确定退出) 或 8 (继续运行)："))
    if over == 4:
        exit()
    if over == 8:
        MainWindow_check()


def Student_register_name():  # 学生权限：注册账号
    name = input("请输入你要注册的邮箱用户名：")

    # 验证此用户名是否存在
    if name.isalpha():  # 判断全英文
        en_name = str("'" + name + "'")
        if en_name in person_name_list:
            print(f"您输入的用户名为{en_name}，此用户名已存在，请重新输入")

    if name in person_name_list:
        print(f"您输入的用户名为{name}，此用户名已存在，请重新输入")

    if name.isspace():  # 判断全空格
        print(f"您输入的用户名为{name}，此用户名无效，请重新输入")

    if name not in person_name_list:
        print(f"您输入的用户名为{name}，可以注册")
        # person_name_dict.extend([name])
        old = input("请输入年龄：")
        gender = str(input("请输入性别："))
        person_name_list.extend([name, old, gender])

    else:
        print("您的输入有误，请重新输入")


def Teacher_register_name():  # 教师 & 管理员权限：注册账号
    name = input("请输入你要注册的学生邮箱用户名：")

    # 验证此用户名是否存在
    if name.isalpha():  # 判断全英文
        en_name = str("'" + name + "'")
        if en_name in person_name_list:
            print(f"您输入的用户名为{en_name}，此用户名已存在，请重新输入")

    if name in person_name_list:
        print(f"您输入的用户名为{name}，此用户名已存在，请重新输入")

    if name.isspace():  # 判断全空格
        print(f"您输入的用户名为{name}，此用户名无效，请重新输入")

    if name not in person_name_list:
        print(f"您输入的用户名为{name}，可以注册")
        # person_name_dict.extend([name])
        old = input("请输入此学生年龄：")
        gender = input("请输入此学生性别：")
        person_name_list.extend([name, old, gender],)
        Teacher_check()


    else:
        print("您的输入有误，请重新输入")


def question():  # 询问是否继续执行程序
    question = int(input("请问您是否要继续执行此程序？输入序号 1 (继续执行) 或 2 (查询用户名) 或 3 (停止运行)："))


def Teacher_check():  # 教师 & 管理员权限：查看学生账号
    question()

    if question == 1:
        Student_register_name()
    if question == 2:
        print("请输入你要查询的用户名：")
        check_name = input()
        if check_name in person_name_list:
            print(f"你输入的用户名{check_name}已在账号管理系统")
        if check_name not in person_name_list:
            print(f"您输入的用户名{check_name}未在账号管理系统")
    if question == 3:
        Main_exit()


def Administrator_PrintAll():  # 管理员权限：利用列表循环遍历实现打印所有数据功能
    for all in person_name_list:
        print(all)


def student():  # 学生权限只能进行普通管理权限
    Student_register_name()


def teacher():  # 教师权限拥有更高级别的管理权限
    Teacher_register_name()


def Administrator():  # 管理员权限拥有最高级别的管理权限
    key = int(input("你要执行的操作是？："
                    "1 查看所有账号"
                    "2 注册账号"
                    "3 查看某个账号"))
    if key == 1:
        Administrator_PrintAll()
    if key == 2:
        Teacher_register_name()
    if key == 3:
        Teacher_check()


def MainWindow_check():  # 主窗口 用于执行所有功能
    start_window()
    print("欢迎您使用账号管理系统")
    print("请问你是 学生 、 教师 或 管理员？"
          "还是退出此系统？")
    num = int(input("请输入数字（学生：1    教师：2    管理员：3    退出：4）："))

    if num == 1:
        student()
    if num == 2:
        teacher()
    if num == 3:
        Administrator()
    if num == 4:
        Main_exit()


while True:     # 重复执行程序
    MainWindow_check()
