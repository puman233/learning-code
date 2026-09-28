
count = 0

for ten in range(20 // 10 + 1):
    for five in range((20 - ten * 10) // 5 + 1):
        one = 20 - ten * 10 - five * 5
        if one >= 0:
            count += 1
            print("10元={}张\t5元={}张\t1元={}张"
                  .format(ten, five, one))

print("总有{}种情况".format(count))
