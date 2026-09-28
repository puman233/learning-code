package Day_03_条件语句;

class for循环语句 {
    public static void main(String[] args) {
        /*
            for语句
        格式：
            for(初始化语句;条件判断语句;条件控制语句) {
                循环体语句;
            }
        执行流程：
            WZQConfig.java.执行初始化语句
            2.执行条件判断语句，看其结果是True还是False
                如果是False，循环结束
                如果是True，继续执行
            3.执行循环体语句
            4.执行条件控制语句
            5.回到2.继续
         */

//        普通输出HelloWorld
        System.out.println("普通输入");
        //需求：输出5次“HelloWorld”
        System.out.println("HelloWorld");
        System.out.println("HelloWorld");
        System.out.println("HelloWorld");
        System.out.println("HelloWorld");
        System.out.println("HelloWorld");

//        用for循环语句输出5次HelloWorld
        System.out.println("for循环");
        //用循环递进
        for (int i = 1; i <= 5; i++) {
            System.out.println("HelloWorld");
        }

//        再次实践
        for (int a = 3; a <= 10; a++) {
            System.out.println("w~w");
        }
    }
}
