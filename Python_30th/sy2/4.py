
for i in range(100, 150, 1):
    if i % 2 == 0:
        continue
    else:
        isS = True
        for j in range(3, int(i ** 1/2), 2):
            if i % j == 0:
                isS = False
                break
        if isS:
            print(i)
