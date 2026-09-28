import time

try:
    f = open("test.txt", "r")
    try:
        while True:
            line = f.readline()
            if len(line) == 0:
                break

            time.sleep(3)
            print(line)
    except:
        print("Error reading")
except:
    print("This test is not working properly")

