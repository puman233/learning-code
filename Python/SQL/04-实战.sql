
create database py_sql char set utf8;

use py_sql;

create table orders(
    order_date date,
    order_id varchar(255),
    money int,
    province varchar(10)
);

# 废弃 delete

drop database py_sql;
