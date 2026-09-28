i = 1
while i <= 9:
    j: int = 1
    while j <= i:
        print(f'{j} * {i} = {i * j}', end='\t')
        j += 1
    print()
    i += 1

print("-----------分割线-------------")

a = 1
while a <= 9:
    b:int = 1
    while a <= b:
        print(f'{b} * {a} = {a * b}',end='\t')
        b += 1
    print()
    a += 1