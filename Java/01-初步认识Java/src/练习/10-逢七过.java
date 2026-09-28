package 练习;

class 逢七过 {
    public static void main(String[] args) {
        //数据在1~100之间，for循环实现数据的获取
        for (int x = 1; x <= 100; x++) {
            //根据规则，用if语句实现数据的判断，要么十位是7，要么能被7整除
            if (x % 7 == 0 || x / 10 % 10 == 7) {
                //控制台输出结果
                System.out.println(x);
            }
        }

        System.out.println("Next --- ");

        for (int i = 1; i <= 100; i++) {
            // 遇到个位是7或被7整除
            if (i % 7 == 0 || i % 10 == 7) {
                System.out.println(i);
            }
        }
    }
}
