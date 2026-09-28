package Day_05_方法;

class 方法 {
    public static void main(String[] args) {
        /*
            方法
            是将具有独立功能的代码块组织成为一个整体，使其具有特殊功能的代码集

         */
    }
}


class 方法定义 {
    public static void main(String[] args) {
        /*
            格式：
                方法名();
                isEvenNumber();
         */

        //需求：定义一个方法，在方法中定义一个变量，判断该数是否是偶数
        //定义变量
        int number = 10;
        number = 9;

        //判断该数据是否是偶数
        if (number%2 == 0) {
            System.out.println(true);
        } else {
            System.out.println(false);
        }
    }
}