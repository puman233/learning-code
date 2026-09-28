package Day_05_方法;

public class _07_递归 {
    static void main(String[] args) {
/*
Java 递归
    递归是进行函数调用本身的技术
    这种技术提供了一种将复杂问题分解为更容易解决的简单问题的方法。
 */
        // 递归：让数字相加
        int result = sum(10);
        System.out.println(result);

        int res = sum(5,10);
        System.out.println(res);



    }
    public static int sum(int k) {
        /*
        调用sum()函数时，它将参数k添加到小于k的所有数字的和中，并返回结果
        当k变为0时，函数只返回0。

        10 + sum(9)
        10 + ( 9 + sum(8) )
        10 + ( 9 + ( 8 + sum(7) ) )
        ...
        10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + sum(0)
        10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + 0

        由于函数在k为0时不调用自身，因此程序停止并返回结果。
         */
        if (k > 0) {
            return k + sum(k - 1);
        } else {
            return 0;
        }
    }
    public static int sum(int start, int end) {
        if (end > start) {
            return end + sum(start, end - 1);
        } else {
            return end;
        }
    }
}




