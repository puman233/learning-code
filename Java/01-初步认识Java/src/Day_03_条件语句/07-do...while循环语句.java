package Day_03_条件语句;

class do___while循环语句 {
    public static void main(String[] args) {
        //需求：输出5次“HelloWorld"
        //for循环实现
        for (int a = 1; a <= 5; a ++) {
            System.out.println("HelloWorld");
        }

        System.out.println("-----------------");

        //do...while循环
        int b = 1;
        do {
            System.out.println("HelloWorld");
            b++;
        } while (b <= 5);
    }
}
