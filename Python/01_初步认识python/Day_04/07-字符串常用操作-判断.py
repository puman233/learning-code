"""
    isalpha():  如果字符串至少有一个字符并且所有字符都是字母返回True，反之返回False

    isdigit():  如果字符串只包含数字返回True，反之返回False

    isalnum():  如果字符串至少有一个字符并且所有字符都是字母或数字返回True，反之返回False

    isspace():  如果字符串中只包含空白，返回True，反之返回False

"""
mystr = "hello world and it will be good when I grow up"
mystr1 = "12345"
mystr2 = "good"
mystr3 = "                            "

# isalpha
a = mystr.isalpha()
print(a)

# isdigit
b = mystr1.isdigit()
print(b)

# isalnum
c = mystr2.isalnum()
print(c)

# isspace
d = mystr3.isspace()
print(d)

