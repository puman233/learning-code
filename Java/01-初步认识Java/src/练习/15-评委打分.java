package 练习;

import java.util.Scanner;

class 评委打分 {
    public static void main(String[] args) {

        System.out.println("本次打分环节共有多位评委打分");
        System.out.println("请选择评委人数：");

        Scanner peopleNum = new Scanner(System.in);
        int Num = peopleNum.nextInt();
        //定义数组，用动态初始化完成数组元素的初始化，长度为6
        int[] arr = new int[Num];

        //键盘录入评委分数
        Scanner sc = new Scanner(System.in);

        //循环改进
        for (int x = 0;x< arr.length;x++){
            System.out.println("请输入第" + (x + 1) + "个评委的打分：");
            arr[x] = sc.nextInt();
        }

        //定义方法实现获取数组中的最高分（数组最大值），调用方法
        int max = getMax(arr);
        //定义方法实现获取数组中的最低分（数组最小值），调用方法
        int min = getMin(arr);
        //定义方法实现获取数组中的所有元素的和（数组元素求和），调用方法
        int sum = getSum(arr);
        //按照计算规则进行计算得到平均分
        int avg = (sum - max - min) / (arr.length - 2);
        //输出平均分
        System.out.println("选手的平均分是：" + avg);
    }

    /*
        两个明确：
            返回值类型：int
            参数：int[] arr
     */

    //求和
    public static int getSum(int[] arr){
        int sum = 0;

        for (int x : arr) {
            sum += x;
        }
        return sum;
    }

    //取最小值
    public static int getMin(int[] arr){
        int min = arr[0];

        for (int x=1;x<arr.length;x++){
            if (arr[x]<min){
                min = arr[x];
            }
        }
        return min;
    }

    //取最大值
    public static int getMax(int[] arr){
        int max = arr[0];

        for (int x=1;x<arr.length;x++){
            if (arr[x]>max){
                max = arr[x];
            }
        }
        return max;
    }
    //遍历数组
    public static void printArray(int[] arr){
        System.out.println();
    }
}
