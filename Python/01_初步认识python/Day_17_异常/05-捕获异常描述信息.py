try:
    print(1/0)
except (NameError, ValueError, TypeError, ZeroDivisionError) as e:
    print(e)
    