package 练习;

public class _23_Lambda {

    /*

    (参数列表) -> {
    方法体
    }

     */

    public static void main(String[] args) {

        CalculateAdd add = (a, b) -> a + b;

        System.out.println("Addition result: " + add.add(10, 20));

        CalculateSubtract sub = (a, b) -> a - b;

        System.out.println("Subtraction result: " + sub.subtract(10, 20));
    }

}

interface CalculateAdd {
    int add(int a, int b);
//    接口中不能有2个抽象方法同时实现
//    double calculate(double x, double y);
}

interface CalculateSubtract {
    int subtract(int a, int b);
}



