"""
    账号管理系统V1.96.008

    新版本特性：
    · 新增用户名姓名输入功能
    · 优化性能
"""


def start_window():
    print("-------------------------------------------------")
    print("*                                               *")
    print("*             账号管理系统 V1.96.088              *")
    print("*                                               *")
    print("-------------------------------------------------")


def check():
    question = int(input("请问您是否要继续执行此程序？输入序号 1 (继续执行) 或 2 (查询用户名) 或 3 (停止运行)："))

    if question == 1:
        register_name()
    if question == 2:
        print("请输入你要查询的用户名：")
        check_name = input()
        if check_name in person_name_list:
            print(f"你输入的用户名{check_name}已在账号管理系统")
        if check_name not in person_name_list:
            print(f"您输入的用户名{check_name}未在账号管理系统")
    if question == 3:
        over = int(input("您真的要退出此程序吗？请输入序号 4 (确定退出) 或 8 (继续运行)："))
        if over == 4:
            exit()
        if over == 8:
            register_name()


person_name_list = []  # 定义列表，用于储存用户名、年龄


def register_name():
    name = input("请输入你要注册的邮箱用户名：")

    # 验证此用户名是否存在
    if name.isalpha():  # 判断全英文
        en_name = str("'" + name + "'")
        if en_name in person_name_list:
            print(f"您输入的用户名为{en_name}，此用户名已存在，请重新输入")
            start_window()

    if name in person_name_list:
        print(f"您输入的用户名为{name}，此用户名已存在，请重新输入")
        start_window()

    if name.isspace():  # 判断全空格
        print(f"您输入的用户名为{name}，此用户名无效，请重新输入")
        start_window()

    if name not in person_name_list:
        print(f"您输入的用户名为{name}，可以注册")
        # person_name_dict.extend([name])
        old = input("请输入年龄：")
        person_name_list.extend([name,old])

        start_window()
        check()


    else:
        print("您的输入有误，请重新输入")
        start_window()


while True:
    register_name()
