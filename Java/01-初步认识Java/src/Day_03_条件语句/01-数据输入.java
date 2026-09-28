package Day_03_条件语句;

import java.util.Scanner;

class 数据输入 {
    public static void main(String[] args) {
        //创建对象
        Scanner sc = new Scanner(System.in);

        //接收数据
        int x = sc.nextInt();

        //输出数据
        System.out.println("x:" + x);

        Scanner sc2 = new Scanner(System.in);

        String name = sc2.nextLine();

        System.out.println("name:" + name);
    }
}
