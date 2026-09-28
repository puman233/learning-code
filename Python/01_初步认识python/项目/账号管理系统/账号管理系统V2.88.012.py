"""
    账号管理系统V2.88.012 Beta

    新版本特性：
        · 优化体验
        · 更新了若干功能
"""
import time

person_name_dict = {}  # 定义字典，用于储存用户名、年龄


def start_window():
    print("-------------------------------------------------")
    print("*                                               *")
    print("*             账号管理系统 V2.88.012 Beta         *")
    print("*                                               *")
    print("-------------------------------------------------")


def main_exit():  # 主窗口退出程序
    over = int(input("您真的要退出此程序吗？请输入序号 4 (确定退出) 或 8 (继续运行)："))
    if over == 4:
        exit()
    if over == 8:
        main_window_check()


def student_register_name():  # 学生权限：注册账号
    def gender():  # 性别识别功能 & 添加数据功能
        gender_list = ['男', '女']
        gender = str(input("请输入性别："))
        if gender in gender_list:
            person_name_dict['用户名'] = name
            person_name_dict['邮箱'] = email
            person_name_dict['年龄'] = old
            person_name_dict['性别'] = gender
        else:
            print(f"您输入的 {gender} 有误，请重新输入")
            student_register_name()

    def old_check():  # 年龄检查程序
        if 0 >= old >= 24:
            print("您的输入有误，请重新输入")
            student_register_name()
        if 0 < old <= 3 and 18 < old < 24:
            print(f"您确定您的年龄是{old}吗？")
            old_key = int(input(f"如果您的年龄是{old}，请输入 1，如果不是，请输入 2"))
            if old_key == 1:
                gender()
            if old_key == 2:
                print("您需要重新输入")
                old_check()
        if 18 >= old > 3:
            gender()

    name = input("请输入你要注册的邮箱用户名：")

    # 验证此用户名是否存在
    if name.isalpha():  # 判断全英文
        en_name = str("'" + name + "'")
        if en_name in person_name_dict:
            print(f"您输入的用户名为{en_name}，此用户名已存在，请重新输入")

    if name in person_name_dict:
        print(f"您输入的用户名为{name}，此用户名已存在，请重新输入")

    if name.isspace():  # 判断全空格
        print(f"您输入的用户名为{name}，此用户名无效，请重新输入")

    if name not in person_name_dict:
        print(f"您输入的用户名为{name}，可以注册")
        time.sleep(0.2)
        print("请稍后…")
        time.sleep(0.8)
        mail = "@std.id"
        email = name + mail
        print(f"您的邮箱账号已自动生成，您的邮箱为：{email}")
        old = int(input("请输入年龄："))
        old_check()

    else:
        print("您的输入有误，请重新输入")


def teacher_register_name():  # 教师 & 管理员权限：注册账号
    def gender():  # 性别识别功能 & 添加数据功能
        gender_list = ['男', '女']
        gender = str(input("请输入性别："))
        if gender in gender_list:
            person_name_dict['用户名'] = name
            person_name_dict['邮箱'] = email
            person_name_dict['年龄'] = old
            person_name_dict['性别'] = gender
        else:
            print(f"您输入的 {gender} 有误，请重新输入")
            teacher_register_name()

    def old_check():
        if 0 >= old >= 24:
            print("您的输入有误，请重新输入")
            student_register_name()
        if 0 < old <= 3 and 18 < old < 24:
            print(f"您确定您的年龄是{old}吗？")
            old_key = int(input(f"如果您的年龄是{old}，请输入 1，如果不是，请输入 2"))
            if old_key == 1:
                gender()
            if old_key == 2:
                print("您需要重新输入")
                old_check()
        if 18 >= old > 3:
            gender()
            teacher_check()

    name = input("请输入你要注册的学生邮箱用户名：")

    # 验证此用户名是否存在
    if name.isalpha():  # 判断全英文
        en_name = str("'" + name + "'")
        if en_name in person_name_dict:
            print(f"您输入的用户名为{en_name}，此用户名已存在，请重新输入")

    if name in person_name_dict:
        print(f"您输入的用户名为{name}，此用户名已存在，请重新输入")

    if name.isspace():  # 判断全空格
        print(f"您输入的用户名为{name}，此用户名无效，请重新输入")

    if name not in person_name_dict:
        print(f"您输入的用户名为{name}，可以注册")
        time.sleep(0.2)
        print("请稍后…")
        time.sleep(0.8)
        mail = "@std.id"
        email = name + mail
        print(f"您的邮箱账号已自动生成，您的邮箱为：{email}")
        old = int(input("请输入此学生年龄："))
        old_check()

    else:
        print("您的输入有误，请重新输入")


def question():  # 询问是否继续执行程序
    question = int(input("请问您是否要继续执行此程序？输入序号 1 (继续执行) 或 2 (查询用户名) 或 3 (停止运行)："))


def teacher_check():  # 教师 & 管理员权限：查看学生账号
    question()

    if question == 1:
        student_register_name()
    if question == 2:
        print("请输入你要查询的用户名：")
        check_name = input()
        if check_name in person_name_dict:
            print(f"你输入的用户名{check_name}已在账号管理系统")
        if check_name not in person_name_dict:
            print(f"您输入的用户名{check_name}未在账号管理系统")
    if question == 3:
        main_exit()


def administrator_print_all():  # 管理员权限：利用列表循环遍历实现打印所有数据功能
    for key, value in person_name_dict.items():
        print(f'{key}：{value}')


def student():  # 学生权限只能进行普通管理权限
    student_register_name()


def teacher():  # 教师权限拥有更高级别的管理权限
    teacher_register_name()


def administrator():  # 管理员权限拥有最高级别的管理权限
    key = int(input("""你要执行的操作是？：
                    1 查看所有账号
                    2 注册账号
                    3 查看某个账号"""))
    if key == 1:
        administrator_print_all()
    if key == 2:
        teacher_register_name()
    if key == 3:
        teacher_check()


def main_window_check():  # 主窗口 用于执行所有功能
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
        administrator()
    if num == 4:
        main_exit()


while True:  # 重复执行程序
    main_window_check()
