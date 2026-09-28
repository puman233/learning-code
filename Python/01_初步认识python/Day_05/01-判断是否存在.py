"""
    in: 判断指定数据在某个列表序列，如果在返回True，反之返回False
        相反：not in
"""
name_list = ['Tom','Lily','Rose']

# in
print('Tom' in name_list)
print('tom' in name_list)

# not in
print('tom' not in name_list)
print('Tom' not in name_list)