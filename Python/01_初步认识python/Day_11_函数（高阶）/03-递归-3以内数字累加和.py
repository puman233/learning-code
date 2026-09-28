# 需求：3以内数字累加和：3 + 2 + 1 = 6
# 6 = 3 + 2 以内数字累加和
# 2以内数字累加和 = 2 + 1以内数字累加和

def sum_number(num):
    if num == 1:
        return 1
    # 当前数字 + 当前数字-1 的累加和
    return num + sum_number(num - 1)


result = sum_number(3)
print(result)

