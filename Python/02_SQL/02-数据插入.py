from pymysql import Connection

con = Connection(
    host='localhost',  # 主机名
    port=3306,  # 端口
    user='root',  # 账户
    password='123456',  # 密码
    autocommit=True  # 自动提交, 默认为False
)

cursor = con.cursor()

con.select_db("world")

cursor.execute("delete from student where id = 14")
cursor.execute("insert into student values(14, 'cg', 24, '男')")

# 通过commit确认修改
# con.commit()

con.close()
