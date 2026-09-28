-- 数据插入
# insert into student(id) values(1), (2), (3), (4);

# 字符串只能使用单引号
insert into student(id, name, age, gender)  value (4, 'lcy', 17, '男'), (8, 'qyn', 10, '女');

-- 数据删除
# delete from student where id = 1;
# delete from student where id >= 8;
# delete from student where age = 17;

-- 数据更新
-- update 表名 set 列 = 将修改为的值 [where 条件判断]
update student set name = 'hrd' where age = 17;
