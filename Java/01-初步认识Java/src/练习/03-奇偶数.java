package 练习;

import java.util.Scanner;

class 奇偶数 {
    public static void main(String[] args) {
        /*
                    案例：奇偶数
        需求：任意给出一个整数，请用程序实现判断该整数是奇数还是偶数

        分析：
            ①为了体现任意给出一个整数，采用键盘输入一个数据
                使用键盘录入功能需要导包：
                    import java.util.Scanner;
                创建对象：
                    Scanner sc = new Scanner(System.in);
                接收数据：
                    int number = sc.nextInt();
            ②判断整数是偶数还是奇数要分两种情况进行判断，使用if...else结构
                if() {

                } else {

                }
            ③判断是否偶数需要用取余运算符实现该功能：
                number % 2 == 0
                    if (number % 2 == 0) {
                    } else {
                    }
            ④根据判定情况，在控制台输出对应的内容
                if (number % 2 == 0) {
                    System.out.println(number + "是偶数");
                } else {
                    System.out.println(number + "是奇数");
                }
         */

        System.out.println("接下来，请你输入一个整数：");

        Scanner sc = new Scanner(System.in);

        int number = sc.nextInt();

        if(number % 2 == 0) {
            System.out.println(number + "是偶数");
        } else {
            System.out.println(number + "是奇数");
        }
    }
}
