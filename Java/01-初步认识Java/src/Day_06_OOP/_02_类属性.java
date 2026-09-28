package Day_06_OOP;

import java.util.Scanner;

class MyClass {
    int x = 6;
}
public class _02_类属性 {

    public static void main(String[] args) {

        /*
        可以说类属性是类中的变量:
        类属性的另一个术语是字段。

        实例
            创建一个名为"MyClass0"的类，该类具有两个属性:x 和 y:

            public class MyClass0 {
              int x = 5;
              int y = 3;
            }
         */

        MyClass0 myClass0 = new MyClass0();
        System.out.println(myClass0.x);

        // 修改类属性值
        myClass0.x = 7;
        System.out.println(myClass0.x);

        // 多个对象
        MyClass0 myClass1 = new MyClass0();
        System.out.println(myClass1.x);
        myClass1.x = 8;
        System.out.println(myClass1.x);


        // 统计字符串各个字符的数量
        //键盘录入字符串
        Scanner sc = new Scanner(System.in);

        System.out.println("请输入一个字符串：");
        String line = sc.nextLine();

        CharactersNumber charactersNumber = new CharactersNumber();
        charactersNumber.Character(line);

    }
}

// 字符次数
class CharactersNumber{
    public void Character(String line) {
        //统计三种类型的字符个数，需定义三个统计变量，初始值为0
        int bigCount = 0;
        int smallCount = 0;
        int numberCount = 0;
        int otherCount = 0;

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
            else {
                otherCount++;
            }

        }

        //输出三种类型的字符个数
        System.out.println("大写字母：" + bigCount + "个");
        System.out.println("小写字母：" + smallCount + "个");
        System.out.println("数字：" + numberCount + "个");
        System.out.println("其他：" + otherCount + "个");
        System.out.println("总共：" + line.length() + '个');
    }
}
