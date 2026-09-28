# 案例

# 打印一条横线
def print_line():
    print("-" * 20)

print_line()

# 打印多条横线
def print_line_many():
    print("-" * 20)

def print_lines(num):
    i = 0
    while i < num:
        print_line_many()
        i += 1

print_lines(5)
