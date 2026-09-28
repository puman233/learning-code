count = 0

user = "admin"
password = "123456"

while count < 3:
    name = input("输入用户名：")
    pa = input("输入密码：")
    if name == user and pa == password:
        print("登陆成功")
        exit()
    else:
        count+=1
        if count < 3:
            print("错误，重新输入")
        else:
            print("错误次数超过3次，退出")
            exit()