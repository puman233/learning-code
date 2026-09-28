package Day_05_方法;

import java.lang.Math;

import static java.lang.Math.pow;

public class _05_方法重载 {

    static int plusMethodInt(int x, int y) {
        return x + y;
    }

    static double plusMethodDouble(double x, double y) {
        return x + y;
    }

    // 方法重载
    static int plusMethod(int x, int y) {
        return x + y;
    }

    static double plusMethod(double x, double y) {
        return x + y;
    }

    public static void main(String[] args) {

        /*
            使用方法重载，多个方法可以具有相同的名称和不同的参数:
                实例
                    int myMethod(int x)
                    float myMethod(float x)
                    double myMethod(double x, double y)
         */

        int myNum1 = plusMethodInt(8, 5);
        double myNum2 = plusMethodDouble(3.14, 3.39);
        System.out.println("int: " + myNum1);
        System.out.println("double: " + myNum2);

        // 方法重载
        // 重载PlusMethod方法以同时适用于int和double二种数据类型:
        int myNum3 = plusMethod(8, 5);
        double myNum4 = plusMethod(3.14, 3.39);
        System.out.println("int: " + myNum3);
        System.out.println("double: " + myNum4);

        // 重写前
        Multiplication multipNum = new Multiplication();
        multipNum.multiplication(8, 5);
        multipNum.multiplication(3.14, 3.39);

        // 方法重写
        Multiplication2 multipNum2 = new Multiplication2();
        multipNum2.multiplication(2, 3);
        multipNum2.multiplication(3.14, 3.39);


    }
}

// 乘算
class Multiplication{
    public void multiplication(int x, int y) {
        System.out.println("x * y = " + (x * y));
    }
    public void multiplication(double x, double y) {
        System.out.println("x * y = " + (x * y));
    }
}

// 方法重写
class Multiplication2 extends Multiplication{
    @Override
    public void multiplication(int x, int y) {
        System.out.println("x的y次方 = " + pow(x, y));
    }
    @Override
    public void multiplication(double x, double y) {
        System.out.println("x的y次方 = " + pow(x, y));
    }
}

