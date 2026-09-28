package 练习;

import java.util.Scanner;

//字符串反转
class goRe {
    public static void main(String[] args) {
        //键盘录入一个字符串，用Scanner实现
        Scanner sc = new Scanner(System.in);

        System.out.println("请输入一个字符串：");
        String line = sc.nextLine();

        //调用方法，用一个变量接受结果
        String s = reverse(line);
        //输出结果
        System.out.println("s:" + s);
    }

    //定义一个方法，实现字符串反转。返回类型用String，参数String s
    public static String reverse(String s){
        //在方法中吧字符串倒着遍历，然后把每一个得到的字符拼接成一个字符串并返回
        StringBuilder ss = new StringBuilder();

        for (int i=s.length()-1;i>=0;i--){
            ss.append(s.charAt(i));
        }

        return ss.toString();
    }
}


/** @noinspection ALL*/ //字符串反转升级版
class newRe{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("请输入一个字符串：");
        String line = sc.nextLine();

        String s = myReverse(line);

        System.out.println("answer:" + s);
    }

    public static  String myReverse(String s){

//        StringBuilder sb  = new StringBuilder(s);
//        sb.reverse();
//        String ss = sb.toString();
//        return ss;

        return new StringBuilder(s).reverse().toString();
    }
}

class newProject{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //将字符串记录在数据中
        System.out.println("请输入一个字符串：");
        //获取输入的数据
        String line = sc.nextLine();
        //将数据转入到函数中进行调用
        String out = myReverse(line);
        //输出结果
        System.out.println("hi:" + out);
    }

    public static String myReverse(String out){
        return new StringBuilder(out).reverse().toString();
    }
}