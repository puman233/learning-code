package Day_05_方法;

/*
    Debug概述
        是供程序员使用的程序调试工具，它可以用于查看程序的执行流程，也可以用于追踪程序执行流程来调试程序
*/

import java.util.Scanner;

class Debug {
    public static void main(String[] args) {
        //定义变量
        int a = 10;
        int b = 20;

        //求和
        int sum = a + b;

        //输出结果
        System.out.println("sum:" + sum);
    }
}


class Debug_1到10偶数求和{
    public static void main(String[] args) {
        //定义求和变量
        int sum = 0;

        //循环求偶数和
        for (int a = 1; a <= 10; a++){
            if (a % 2 == 0){
                sum += a;
            }
        }
        System.out.println("WZQConfig.java~10之间的偶数和是：" + sum);
    }
}

class Debug_1到100奇数求和{
    public static void main(String[] args) {
        int num = 0;

        for (int b = 1; b <= 100; b++) {
            if (b % 2 != 0) {
                num += b;
            }
        }

        System.out.println("WZQConfig.java~100奇数和是：" + num);
    }
}



//方法调用
class Debug_方法调用{
    public static void main(String[] args) {
        //创建对象
        Scanner sc = new Scanner(System.in);

        //接收数据
        System.out.println("请输入第一个整数：");
        int a = sc.nextInt();

        System.out.println("请输入第二个整数");
        int b =  sc.nextInt();

        //调用方法
        int max = getMax(a,b);

        //输出结果
        System.out.println("较大的值是：" + max);
    }

    //获取两数较大值
    public static int getMax(int a,int b){
        if (a > b){
            return a;
        }else {
            return b;
        }
    }
}