for i in range(1, 10):
    for j in range(1, 10):
        print(
            "{}*{}={:<2}".format(i, j, i * j), end="  "
        )
    print()

print()
for i in range(1, 10):
    print("        " * (i - 1), end='')
    for j in range(i, 10):
        print(
            "{}*{}={:<2}".format(i, j, i * j), end="  "
        )
    print()

print()
for i in range(1, 10):
    for j in range(1, i + 1):
        print(
            "{}*{}={:<2}".format(j, i, i * j), end="  "
        )
    print()
