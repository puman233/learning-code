package 练习;

import java.util.Scanner;

class 不死神兔 {
    public static void main(String[] args) {
        /*
            版本号：V1.02
         */
        /*
            故事：有一只兔子，从出生后第三个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子
                假如兔子都不死，问：第二十个月的兔子对数为多少？
         */
        //为了储存多个月的兔子对数，定义一个数组，用动态初始化完成数组元素的初始化，长度为20
        int[] arr = new int[20];

        //第一个月，第二个月的兔子对数是已知的，都是1，所以数组的第一个元素和第二个元素都是1
        arr[0] = 1;
        arr[1] = 1;

        //用循环实现计算每个月的兔子对数
        for (int x = 2; x < arr.length; x++) {
            arr[x] = arr [x-2] + arr[x - 1];
        }

        //输出数组中最后一个元素的值，就是第20个月的兔子对数
        System.out.println("第二十个月兔子的对数是：" + arr[19]);
    }
}


class 不死神猫 {
    public static void main(String[] args) {
        /*
            版本号：V2.08
            新版本声明：
                - 新增查询功能
                - 优化体验
         */
        /*
            不死神兔升级版——不死神猫

            故事：有一对猫，从出生后第4个月起每个月都生一对猫，小猫长到第4个月后每个月又生一对猫
                假如猫都不死，问：两年后猫的对数为多少？
         */
        //储存多个月的猫的个数，定义数组，用动态初始化完成数组元素的初始化。2年=24个月，所以长度为24
        int[] arr = new int[24];

        //第一个月猫的个数已知，是1。第二，第三个月猫的对数都已知，为1
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 1;

        //用循环实现计算每个月猫的对数
        for (int m = 3; m < arr.length; m++) {
            arr[m] = arr[m - 3] + arr[m - 2] + arr[m - 1];
        }

        //进入程序
        System.out.println("故事：有一对猫，从出生后第4个月起每个月都生一对猫，小猫长到第4个月后每个月又生一对猫\n" +
                "假如猫都不死，问：两年后猫的对数为多少？");
        System.out.println("程序已经计算出1~24个月猫数量的多少，你可以查看数据");
        //提问，输出第几个月的值
        System.out.println("请问你是要查看第几个月的数据（暂时只有第 WZQConfig.java 月，第 5 月，第 10 月，第 15 月，第 20 月，第 24 月的数据）" +
        "   请输入月份");
        Scanner sc = new Scanner(System.in);    //创建数据

        int dataMao = sc.nextInt();   //接收数据

        //判断数据
        switch (dataMao){
            case 1:
                System.out.println("第一月有" + arr[0] + "只猫");
                break;
            case 5:
                System.out.println("第五个月有" + arr[4] + "只猫");
                break;
            case 10:
                System.out.println("第十个月有" + arr[9] + "只猫");
                break;
            case 15:
                System.out.println("第十五个月" + arr[14] + "只猫");
                break;
            case 20:
                System.out.println("第二十个月有" + arr[19] + "只猫");
                break;
            case 24:
                System.out.println("第二十四个月有" + arr[23] + "只猫");
                break;
        }

    }
}