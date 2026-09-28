package 练习;

//import java.awt.*;
import java.util.Scanner;

class 春夏秋冬 {
    public static void main(String[] args) {
        /*
            春夏秋冬

            需求：
                一年有12个月，有春夏秋冬4个季节，键入一个月份，实现判断该月份属于哪个季节

            春：3、4、5
            夏：6、7、8
            秋：9、10、11
            冬：12、1、2
         */

        //键入月份数据，使用变量接受
        Scanner sc = new Scanner(System.in);

        System.out.println("请输入一个月份数（WZQConfig.java~12）：");
        int month = sc.nextInt();

        //多种情况判断时，采用switch语句实现
        switch (month) {
            case 1:
                System.out.println("冬季");
                break;
            case 2:
                System.out.println("冬季");
                break;
            case 3:
                System.out.println("春季");
                break;
            case 4:
                System.out.println("春季");
                break;
            case 5:
                System.out.println("春季");
                break;
            case 6:
                System.out.println("夏季");
                break;
            case 7:
                System.out.println("夏季");
                break;
            case 8:
                System.out.println("夏季");
                break;
            case 9:
                System.out.println("秋季");
                break;
            case 10:
                System.out.println("秋季");
                break;
            case 11:
                System.out.println("秋季");
                break;
            case 12:
                System.out.println("冬季");
                break;
        }
        if (month != 1 && month != 2 && month != 3 && month != 4 && month != 5 && month != 6 && month != 7 && month != 8 && month != 9 && month != 10 && month != 11 && month != 12) {
            System.out.println("请确保你输入的数字为1~12（整数），或者再次运行程序");
        }
    }
}
