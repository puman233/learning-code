name_list = ['Tom','Amy','Lily','Bob']

# 需求：注册邮箱，用户输入一个用户名，判断该用户名是否存在

name = input("请输入您要注册的邮箱用户名：")

if name in name_list:
    # 提示用户名已存在
    print(f"您输入的名字是{name}，此用户名已存在")
else:
    # 提示可以注册
    print(f"您输入的用户名是{name}，可以注册")
    name_list.extend(name)




