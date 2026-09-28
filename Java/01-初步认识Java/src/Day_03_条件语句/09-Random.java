package Day_03_条件语句;

import java.util.Random;
import java.util.Scanner;

class Random2 {
   public static void main(String[] args) {
       /*
           Random

           作用：产生一个随机数
        */
       //创建对象
        Random r = new Random();

       //用循环获取10个随机数
       for (int b = 0; b < 10; b++) {
           //获取随机数
           int number = r.nextInt(100); //获取一个0~99之间的随机数
           System.out.println("number:" + number);
       }

       //需求：获取一个1~100之间的随机数
       int x = r.nextInt(100) + 1;
       System.out.println(x);
   }
}
