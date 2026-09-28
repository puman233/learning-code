"""
    lstrip():   删除字符串左侧空白字符

    rstrip():   删除字符串右侧空白字符

    strip():    删除字符串两侧空白字符
"""
Mypython = "       Hello world my python             "
print(Mypython)

# lstrip()
a1 = Mypython.lstrip()
print(a1)

# rstrip()
a2 = Mypython.rstrip()
print(a2)

# strip()
a3 = Mypython.strip()
print(a3)