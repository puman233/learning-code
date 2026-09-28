package Day_06_OOP;

import java.util.Scanner;

public class _16_Scanner {

/*
Java 用户输入
    Scanner 类用于获取用户输入，它位于 java.util包中。

    要使用 Scanner 类，请创建该类的对象，
    并使用 Scanner 类文档中的任何可用方法。

    方法	            描述
    nextBoolean()	    从用户处读取boolean布尔值
    nextByte()	        从用户处读取byte字节值
    nextDouble()	    从用户处读取double双精度值
    nextFloat()	        从用户处读取float浮点值
    nextInt()	        从用户处读取int值
    nextLine()	        从用户处读取String字符串值
    nextLong()	        从用户处读取long值
    nextShort()	        从用户处读取short值

    如果输入错误（例如数字输入中的文本），
    将收到异常/错误消息 (如 "InputMismatchException")
 */

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);

        System.out.println("Enter name, age and salary:");

        // 字符串输入
        String name = myObj.nextLine();

        // 数字输入
        int age = myObj.nextInt();
        double salary = myObj.nextDouble();

        // 输出用户输入
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Salary: " + salary);
    }


}
