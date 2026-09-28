x = float(input("请输入PM2.5值："))

if x >= 0 and x < 35:
    print("优")
elif x >= 35 and x <= 75:
    print("良")
elif x > 75:
    print("污染")
else:
    print("error")