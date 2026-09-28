# 接着上一课的内容
# 创建空列表
list1 = []

for i in range(10):
    list1.append(i)
    
print(list1)

def dataprint():
    print("-"* 10 + "分割线" + "-"* 10)

dataprint()

# 创建有规律的列表——1~50(0~49)
list2 = []

for p in range(50):
    list2.append(p)

print(list2)

dataprint()

# 2. 列表推导式的实现

list3 = [i for i in range(10)]
print(list3)
