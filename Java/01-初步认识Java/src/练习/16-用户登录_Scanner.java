package 练习;

import java.util.Scanner;

/*
    需求：
        已知用户名和密码，请用程序是心啊模拟用户登录。
        总共给三次机会，登录后，给出相应的提示
 */

class 用户登录_Scanner {
    public static void main(String[] args) {
        //已知用户名和密码，用两个字符串表示
        String username = "itheima";
        String password = "1234";

        //用for循环实现多次机会
        for (int i=0;i<3;i++) {
            //键盘录入要登陆的用户名和密码
            Scanner sc = new Scanner(System.in);

            System.out.println("请输入用户名：");
            String name = sc.nextLine();

            System.out.println("请输入密码");
            String pwd = sc.nextLine();

            //键盘录入用户名，密码和已知的用户名、密码进行比较，给出相应的提示。
            if (name.equals(username) && pwd.equals(password)) {
                System.out.println("登录成功");
                break;
            } else {
                if (2 - i == 0) {
                    System.out.println("您的账户已被锁定，请与管理员联系");
                }else {
                    System.out.println("登录失败，您还有" + (2 - i) + "次机会");
                }
            }
        }
    }
}
