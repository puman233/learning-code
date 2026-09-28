package Day_06_OOP;

import java.time.LocalDate;
import java.time.LocalTime;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class _17_Time {

/*
Java 日期
    Java没有内置的Date类，
    但是我们可以导入java.time 包来使用Date和time API。
    该包包括许多日期和时间类。

    例如:
    类	                描述
    LocalDate	        表示日期（年、月、日（yyyy-MM-dd））
    LocalTime	        表示时间（小时、分钟、秒和纳秒（HH-mm-ss-ns））
    LocalDateTime	    表示日期和时间（yyyy-MM-dd-HH-MM-ss-ns）
    DateTimeFormatter	格式化显示日期时间

显示当前日期
    请导入java.time.LocalDate类，并使用其now()方法

显示当前时间
    请导入 java.time.LocalTime 类，并使用其now()方法

显示当前日期和时间
    请导入 java.time.LocalDateTime 类，并使用其now()方法
    中的"T"用于将日期与时间分开

格式化日期和时间
    使用DateTimeFormatter类和ofPattern()方法格式化或解析日期时间对象

如果希望以不同的格式显示日期和时间，
则 ofPattern() 方法接受所有类型的值。

    例如:
    值	                实例
    yyyy-MM-dd	        "1988-09-29"
    dd/MM/yyyy	        "29/09/1988"
    dd-MMM-yyyy	        "29-Sep-1988"
    E, MMM dd yyyy	    "Thu, Sep 29 1988"

 */

    public static void main(String[] args) {
        LocalDate myObj = LocalDate.now(); // 创建日期对象
        System.out.println(myObj); // 显示当前日期

        LocalTime myObj1 = LocalTime.now();
        System.out.println(myObj1);

        LocalDateTime myObj2 = LocalDateTime.now();
        System.out.println(myObj2);

        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
        DateTimeFormatter dtf2 = DateTimeFormatter.ofPattern("yyyy年 MMM dd日 HH:mm:ss");
        String formattedDate = myObj2.format(dtf);
        String formattedTime = myObj2.format(dtf2);
        System.out.println(formattedDate);
        System.out.println(formattedTime);

    }

}
