"""
    驾驶系统

    需求：乘客在驾驶途中，会记录驾驶里程，请运用本程序来计算乘客的驾驶费用

    价格：
        - 起步价，小于或等于3km时，付款6元
        -
"""
while True:
    km = input("请输入本次驾驶里程数：")
    km = int(km)  # 将 km 数转换为可识别的整数
    cost = 0  # 原始花费数
    if 0 < km <= 3:  # 第一条件
        cost = 6
        print("请支付：")
        print(cost)
        print("元")
    else:
        if 3 < km <= 25:  # 第二条件
            cost = 6 + 2 * (km - 3)
            print("请支付：")
            print(cost)
            print("元")
        else:
            if 25 < km <= 50:  # 第三条件
                cost = 6 + 2 * (25 - 3) + 2.6 * (km - 25)
                print("请支付：")
                print(cost)
                print("元")
            else:
                if 50 < km <= 70:  # 第四条件
                    cost = 6 + 2 * (25 - 3) + 2.6 * (50 - 25) + 3 * (km - 50)
                    print("请支付：")
                    print(cost)
                    print("元")
                else:
                    if km > 70:  # 第五条件
                        cost = 6 + 2 * (25 - 3) + 2.6 * (50 - 25) + 3 * (70 - 50) + 3.5 * (km - 70)
                        print("请支付：")
                        print(cost)
                        print("元")
