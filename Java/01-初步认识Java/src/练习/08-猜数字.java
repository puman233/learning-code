package 练习;

import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

class 猜数字V1 {
    public static void main(String[] args) {
        /*
            猜数字V1.001

            需求：
                自动生成一个1~100的数字，使用程序猜出此数字是多少
         */
        //要完成猜数字的游戏，首先需要有一个要猜的数字，使用随机生成的数，范围自定
        Random num = new Random();
        int number = num.nextInt(100) + 1;  //生成1~100的数

        while (true) {
            //使用程序猜数字，每次均输入猜测的数值，需要使用键盘录入实现
            Scanner sc = new Scanner(System.in);

            System.out.println("请输入你要猜的数字：");
            int guessnumber = sc.nextInt();

            //比较输入的数字和系统产生的数据，需要使用分支语句，这里使用if...else...if..格式，根据不同情况进行结果显示
            if (guessnumber > number) {
                System.out.println("你猜的数字" + guessnumber + "大了");
            } else if (guessnumber < number) {
                System.out.println("你猜的数字" + guessnumber + "小了");
            } else {
                System.out.println("恭喜你，猜中了！");
                break;
            }
        }
    }
}


class 猜数字V2 {
    public static void main(String[] args) throws InterruptedException {
        /*
            猜数字V2.001

            新版本特性：
                - 新增时间暂停功能
                - 优化体验

            需求：程序自动生成一个 1~500的数字，用程序猜出此数字是多少
         */
        //使用随机生成的数
        Random dataNum = new Random();
        int dataNumber = dataNum.nextInt(500) + 1;  //生成 1~500 的数

        //进入程序
        while (true) {
            Random dataTime = new Random();
            int dataTimeOverNumber = dataTime.nextInt(5) + 2;   //生成随机游戏结束时间数2~5秒

            Random dataTimeKeep = new Random();
            int dataTimeKeepNumber = dataTimeKeep.nextInt(3) + 1;   //生成游戏进行时间数1~3秒
            System.out.println("本局猜数字，范围：WZQConfig.java~500");

            Scanner dataSc = new Scanner(System.in);    //键盘录入玩家要猜的数字
            System.out.println("请输入你猜的数字：");
            int dataGuess = dataSc.nextInt();

            //比较数字的大小
            if (dataGuess > dataNumber) {
                System.out.println("你输入的数字大了");
                TimeUnit.SECONDS.sleep(dataTimeKeepNumber);  //暂停
                System.out.println("你要猜的数字应该小于" + dataGuess);
            } if (dataGuess < dataNumber) {
                System.out.println("你输入的数字小了");
                TimeUnit.SECONDS.sleep(dataTimeKeepNumber);  //暂停
                System.out.println("你要猜的数字应该大于" + dataGuess);
            } if (dataGuess == dataNumber){
                System.out.println("恭喜你，猜中了");
                TimeUnit.SECONDS.sleep(dataTimeOverNumber);
                System.out.println("整理中~");
                TimeUnit.SECONDS.sleep(dataTimeOverNumber); //随机暂停几秒
                System.out.println("数字为：" + dataNumber);
                break;
            }
        }

    }
}

class 猜数字V3{
    public static void startWindow(){
        System.out.println("");
        System.out.println("欢迎来到 猜数字 ！");
        System.out.println("");
    }
    public static void exitWindow(){
        System.out.println("您是否要退出此程序？");
        System.out.println("如果您真的需要离开，请输入 1 。或者还想玩，请输入 2 ");
        Scanner exitKey = new Scanner(System.in);
        int exitNum = exitKey.nextInt();
        if (exitNum == 1) {

        }
        if (exitNum == 2){

        }
    }
    public static void main(String[] args) {
        /*
            猜数字V3.001
         */
        startWindow();  //程序入口

        Random PCNum = new Random();    //定义系统要猜的数字范围：   1 ~ 10
        int PCNumber = PCNum.nextInt(10) + 1;


    }
}