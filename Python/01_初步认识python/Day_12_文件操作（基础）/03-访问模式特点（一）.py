"""
测试目标
1.访问模式对文件的影响
2.访问模式对write()的影响
3.访问模式是否可以省略
"""

# r | 如果文件不存在，报错 & 不支持写入操作，表只读
f = open('test.txt', 'r')
f.close()

# w | 只写 & 如果文件不存在，新建文件 & 执行写入，会覆盖原有内容
a = open('1.txt', 'w')
a.write('HelloWorld')
a.close()

# a | 追加
h = open('2.txt', 'a')
h.write('HelloWorld')
h.close()

# 访问模式参数可以省略，如果省略表示访问模式为r
r = open('1.txt')
r.close()

