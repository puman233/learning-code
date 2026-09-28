# 求三个数之和
def sum_num(a,b,c):
    return a + b + c

result = sum_num(1,2,3)
print(result)

# 求三个数平均值

def average_num(a,b,c):
    # 先求和，再除以3
    sumResult = sum_num(a,b,c)
    return sumResult / 3

result_2 = average_num(1,2,3)
print(result_2) # 2.0


