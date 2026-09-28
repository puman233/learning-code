package 练习;

public class _22_第3章作业 {
    public static void main(String[] args) {
        // 求阶乘和，10!
        int n = 10, sum = 0;
        FactorSum factorSum = new FactorSum();
        for (int i = n; i >= 1; i--) {
            sum += factorSum.factorial(i);
        }
        System.out.println(sum);

        // 求100内素数
        Prime prime = new Prime();
        for (int i = 2; i <= 100; i++) {
            if (prime.prime(i)) {
                System.out.print(i + "\t");
            }
        }
        System.out.println();

        // 求分数阶乘和
        FactorSum2 factorSum2 = new FactorSum2();
        double sum2 = 0;
        for (int i = 1; i <= 20; i++) {
            sum2 += 1.0 / factorSum2.factorial(i);
        }
        System.out.println(sum2);

        // 求1000内完数
        Completion completion = new Completion();
        for (int i = 1; i <= 1000; i++) {
            if (completion.complete(i)) {
                System.out.print(i + "\t");
            }
        }
        System.out.println();

        // 8的n项和
        Sum8 sum8 = new Sum8();
        long sum3 = 0;
        for (int i = 1; i <= 10; i++) {
            sum3 += sum8.sum(i);
        }
        System.out.println(sum3);

        // 找最大
        FindMax findMax = new FindMax();
        System.out.println(findMax.findMax());


    }


}

// 阶乘的和
class FactorSum{
    public int factorial(int n){
        if(n==1){
            return 1;
        }
        return n*factorial(n-1);
    }
}

// 求100内全部素数
class Prime{
    public boolean prime(int n){
        if (n == 1) {
            return true;
        };
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}

// 分数阶乘和
class FactorSum2{
    public double factorial(int n){
        if (n <= 1) {
            return 1;
        }
        double sum = n;
        do {
            sum = sum * (n - 1);
            n--;
        } while(n > 1);
        return sum;
    }
}

// 完数
/*
一个正整数等于它的所有真因子（即除了自身以外的约数）之和，
这个数就是完数。
 */
class Completion{
    public boolean complete(int n){
        if (n == 1) {
            return false;
        }
        else {
            int sum = 0;
            for (int i = 1; i <= n / 2; i++) {
                if (n % i == 0) {
                    sum += i;
                }
            }
            return sum == n;
        }
    }
}

// 8的n项和
class Sum8 {
    public long sum(int n){
        long res = 0;
        for (int i = 1; i <= n; i++) {
            res = res * 10 + 8;
        }
        return res;
    }
}

class FindMax{
    public int findMax(){
        int sum = 0, n = 0;
        while (sum < 8888) {
            n++;
            sum += n;
        }
        return n - 1;
    }
}