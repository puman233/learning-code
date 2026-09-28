insert into student(id, name, age, gender)  value (5, 'lhy', 11, '女'), (6, 'lx', 10, '男'), (9, 'lcy', 9, '男'), (10, 'wh', 18, '男'), (11, 'lyy', 19, '女');

-- from:从表中查询某些列
select id, name, age from student;
-- * 从表中查询所有列
select * from student;

-- where 条件判断
select * from student where age <= 14;

-- select 字段, 聚合函数 from 表 [where 条件] group by 列
select gender, avg(age) from student group by gender; # 平均值
select gender, min(age) from student group by gender; # 最小值

select gender, avg(age), sum(age), min(age), max(age), count(*) from student group by gender;

-- order: 默认升序 asc ; 降序 desc
select * from student where age <= 30 order by age asc;

-- limit 限制数量，
select * from student limit 5;
-- 3, 2: 跳过前3条，从第4条开始取2条数据
select * from student limit 3, 2;

select age, count(*) from student where age <= 30 group by age
order by age limit 3;

/*
 条件限制语句 顺序：
    where
    group by
    order by
    limit
 */

