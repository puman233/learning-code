count = 0

for i in range(1, 5):
    for j in range(1, 5):
        for k in range(1, 5):
            if count >= 15:
                exit()
            print(i*100+j*10+k, end='  ')
            count+=1
        print()
    print()