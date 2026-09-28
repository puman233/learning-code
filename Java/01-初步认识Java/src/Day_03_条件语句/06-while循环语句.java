package Day_03_条件语句;

class while循环语句 {
    public static void main(String[] args) {
        //需求：在控制台输出5次'HelloWorld'
        //for 循环实现
        for (int i = 1; i <= 5; i++) {
            System.out.println("HelloWorld");
        }

        System.out.println("-----分割线-----");

        //while循环实现
        int a = 1;
        while(a <= 5) {
            System.out.println("HelloWorld");
            a++;
        }
    }
}
