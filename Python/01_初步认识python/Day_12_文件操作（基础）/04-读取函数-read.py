f = open('test.txt', 'r')

# 文件内容如果换行，底层有\n，会有字节占位，导致read读写参数读写出来的和眼睛看到的个数和参数不匹配
# read 不谢参数表示读取所有
print(f.read())
f.close()
