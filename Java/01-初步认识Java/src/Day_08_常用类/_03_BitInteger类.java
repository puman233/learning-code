package Day_08_常用类;

import java.math.BigInteger;

// int 32位
// long 64位

public class _03_BitInteger类 {

    public static void main(String[] args) {

        // 所有运算方法都不会修改原对象，而是返回一个全新的 BigInteger 对象

        // 常量对象
        BigInteger zero = BigInteger.ZERO;
        BigInteger one = BigInteger.ONE;
        BigInteger two = BigInteger.TWO;
        BigInteger TEN = BigInteger.TEN;


        BigInteger a = new BigInteger("100");
        BigInteger b = new BigInteger("30");

        BigInteger resAdd = a.add(b);       // 加法
        BigInteger resSub = a.subtract(b);  // 减法
        BigInteger resMul = a.multiply(b);  // 乘法
        BigInteger resDiv = a.divide(b);    // 除法
        BigInteger resRem = a.remainder(b); // 取余
        System.out.println(resAdd);
        System.out.println(resSub);
        System.out.println(resMul);
        System.out.println(resDiv);
        System.out.println(resRem);
        System.out.println();

        BigInteger neg = new BigInteger("-50");

        BigInteger resAbs = neg.abs();            // 绝对值
        BigInteger resNeg = a.negate();           // 相反数
        BigInteger resPow = b.pow(3);     // 次方

        BigInteger c = new BigInteger("15");
        BigInteger resGcd = b.gcd(c);             // 最大公约数
        System.out.println(resAbs);
        System.out.println(resNeg);
        System.out.println(resPow);
        System.out.println(resGcd);
        System.out.println();

        // 判断两个大整数的值是否完全相等
        boolean isEqual = a.equals(b);
        System.out.println(isEqual);

        BigInteger maxVal = a.max(b);
        BigInteger minVal = a.min(b);
        System.out.println(maxVal);
        System.out.println(minVal);
        System.out.println();


        BigInteger bigInteger = new BigInteger("14280342180853018539250");
        BigInteger resPower = bigInteger.pow(bigInteger.bitLength());
        System.out.println(resPower);
        System.out.println(bigInteger);



    }


}
