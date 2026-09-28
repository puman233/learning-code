package Day_03_条件语句;

class if语句 {
    public static void main(String[] args) {
        /*
        if语句格式：
            if (关系表达式) {
                语句体;
            }

        执行流程：
            WZQConfig.java.首先计算关系表达式的值
            2.如果关系表达式的值为True就执行语句体
            3.如果关系表达式的值为False就不执行语句体
            4.继续执行后面的语句内容
         */

        //定义变量
        int a = 10;
        int b = 20;
        int c = 10;
        //需求：判断 a 和 b 的值是否相等，如果相等，就在控制台输出：a = b
       if(a == b) {
           System.out.println("a = b");
       }

       //需求：判断 a 和 c 的值是否相等，如果相等，就在控制台输出：a = c
        if(a == c) {
            System.out.println("a = c");
        }
    }
}
