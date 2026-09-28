package 练习;

import java.util.Scanner;

class 遍历字符串_String {
    public static void main(String[] args) {
        //键盘录入字符串
        Scanner sc = new Scanner(System.in);

        System.out.println("请输入一串英文");
        String line = sc.nextLine();

        //遍历字符串
//        System.out.println(line.charAt(0));
//        System.out.println(line.charAt(1));
//        System.out.println(line.charAt(2));

//        for (int a = 0;a < 3 ; a++){
//            System.out.println(line.charAt(a));
//        }

        //遍历字符串，获取字符串的长度
        //System.out.println(line.length());

        for (int a = 0;a < line.length(); a++){
            System.out.println(line.charAt(a));
        }
    }
}
