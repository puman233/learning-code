
m = int(input("请输入月份："))

match m:
    case 3 | 4 | 5:
        print("春季")
    case 6 | 7 | 8:
        print("夏季")
    case 9 | 10 | 11:
        print("秋季")
    case 12 | 1 | 2:
        print("冬季")
