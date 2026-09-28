package Day_05_方法;

/*
    带参数方法定义
        格式：public static void 方法名(参数){...}

        单个参数：
        格式：public static void 方法名(数据类型 变量名){...}
        范例：public static void is EvenNumber(int number){...}

        多个参数：
        格式：public static void 方法名(数据类型 变量名,数据类型 变量名,...){...}
        范例：public static void getMax (int number1, int number2){...}
 */
class 带参数方法的定义与调用 {
    public static void main(String[] args) {
        //常量值的调用
        isEvenNumber(10);

        //变量的调用
        int number = 10;
        isEvenNumber(number);
    }

    //需求：定义一个方法，该方法接受一个参数，判断该数是否为偶数
    public static void isEvenNumber(int number) {
        if (number % 2 == 0) {
            System.out.println(true);
        } else {
            System.out.println(false);
        }
    }
}


class 练习 {
    public static void main(String[] args) {
        /*
            需求：
                设计一个方法用于打印两个数的较大数，数据来源于方法参数
         */
        //在main()方法中调用定义好的方法（使用常量）
        getMax(10,20);
        //调用方法时，人家要几个，你就给几个，人家要什么类型的，你就给什么类型的
        //getMax(30);
        //getMax(10.0,20.0);

        //在main()方法中调用定义好的方法
        int a = 10;
        int b = 20;
        getMax(a,b);
    }

    public static void getMax(int a, int b) {
        //使用分支语句分两种情况对两个数字的大小关系进行处理
        if (a > b) {
            System.out.println(a);
        } else {
            System.out.println(b);
        }
    }
}