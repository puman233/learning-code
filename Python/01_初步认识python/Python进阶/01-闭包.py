def outer(logo):
    def inner(msg):
        print(f"<{logo}>{msg}<{logo}>")

    return inner


fn1 = outer("lcy")
fn1("good")

fn2 = outer("hello")
fn2("nice")


def outer2(num1):
    def inner2(num2):
        nonlocal num1
        num1 += num2
        print(num1)

    return inner2


test1 = outer2(int(input()))
test1(10)


# 案例
def account_create(initial_amount=0):

    def atm(num, deposit=True):
        nonlocal initial_amount
        if deposit:
            initial_amount += num
            print(f"存款：+{num}，账户余额：{initial_amount}")
        else:
            initial_amount -= num
            print(f"取款：-{num}，账户余额：{initial_amount}")

    return atm


atm = account_create()
atm(100)
atm(200)
# Hello World
