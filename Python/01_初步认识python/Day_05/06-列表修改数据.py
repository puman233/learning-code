"""
    reverse():   逆置

    sort():     排序
    语法：
        列表序列.sort(key = None,reverse = False)
        其中 reverse = True表降序，reverse = False表升序(默认)
"""
name_list = ['Tom','Amy','Rose']

# 修改
# name_list[0] == 'hhh'
# print(name_list)

# 逆序
list1 = [1,3,2,5,4,6]
# list1.reverse()
# print(list1)

# sort()
# list1.sort(reverse=False)
list1.sort(reverse=True)
print(list1)