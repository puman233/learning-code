package Day_04_数组;

class 数组常见操作之获取最大量值 {
    public static void main(String[] args) {
        /*
            获取量值
                获取数组中的最大值
         */
        //定义数组
        int[] arr = {12,234,1223,85,603,20};

        //定义一个变量，用于保存最大值
        //取数组中的第一个数据作为变量的初始值
        int max = arr[0];

        //与数组中的神域点数据逐个对比，每次比对将最大值保存到变量中
        for (int x = 1; x < arr.length; x++){
            if (arr[x] > max) {
                max = arr[x];
            }
        }
        //循环结束后打印变量值
        System.out.println("最大值=" + max);
    }
}


class 数组常见操作之获取最小量值 {
    public static void main(String[] args) {
        //定义数组
        int[] arr = {21,2,4125,315,315,461,3,154161,3,15,64,1,46};

        //定义变量，用于储存最小值
        //取数组中的第一个数组作为变量的初始值
        int least = arr[0];

        //进行对比，取最小值
        for (int l = 1; l < arr.length; l++) {
            if (arr[l] < least) {
                least = arr[l];
            }
        }
        //得出最后结果
        System.out.println("最小值=" + least);
    }
}
