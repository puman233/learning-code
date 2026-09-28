from pymysql import Connection

con = Connection(
    host='localhost',  # 主机名
    port=3306,  # 端口
    user='root',  # 账户
    password='123456'  # 密码
)

# 查看版本
# print(con.get_server_info())

##
#
# 游标对象.execute()执行SQL语句
#
###

# 获取游标对象
cursor = con.cursor()

# 选择数据库
con.select_db("world")

# 使用游标对象
# cursor.execute("create table test_pymysql(id int)")

# 查询
cursor.execute("select * from student")

results = cursor.fetchall()
# print(results)

for r in results:
    print(r)

# 关闭链接
con.close()
