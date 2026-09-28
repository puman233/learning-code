package 练习;

import java.awt.font.TextLayout;
import java.util.Scanner;

class 统计字符次数_String {
    public static void main(String[] args) {
        //键盘录入字符串
        Scanner sc = new Scanner(System.in);

        System.out.println("请输入一个字符串");
        String line = sc.nextLine();

        //统计三种类型的字符个数，需定义三个统计变量，初始值为0
        int bigCount = 0;
        int smallCount = 0;
        int numberCount = 0;

        //遍历字符串，得到每一个字符
        for (int a = 0; a < line.length(); a++){
            char ch = line.charAt(a);

            //判断字符输入哪种类型
            if (ch > 'A' && ch <= 'Z'){
                bigCount++;
            }else if (ch >='a' && ch <= 'z'){
                smallCount++;
            }else if (ch >='0' && ch <= '9'){
                numberCount++;
            }
        }

        //输出三种类型的字符个数
        System.out.println("大写字母：" + bigCount + "个");
        System.out.println("小写字母：" + smallCount + "个");
        System.out.println("数字：" + numberCount + "个");
        System.out.println("总共：" + line.length() + '个');
    }
}
