package 练习;

class 数组元素求和 {
    public static void main(String[] args) {
        /*
            数组元素求和
            要求：求和的元素个位和十位都不能是7，且只能是偶数
         */
        //定义一个数组，用静态初始化完成数组元素的初始化
        int[] arr = {121,24,5,2,36,52,57,24,445,146,57,2,45,15,465,72,1,5623,11,61,72,4};

        //定义一个求和的变量，初始值为0
        int numberMax = 0;

        //遍历数组,或取数组中的每一个元素
        for (int dataNum = 0; dataNum < arr.length; dataNum++){
            //判断该元素是否满足条件，如果满足条件就相加
            if (arr[dataNum] % 10 != 7 && arr[dataNum] / 10 % 10 == 7 && arr[dataNum] % 2 == 0) {
                numberMax += arr[dataNum];
            }
        }

        //输出求和变量的值
        System.out.println("求和总数为" + numberMax);
    }
}


class 数组元素相同 {
    public static void main(String[] args) {
        //定义两个数组
        int[] arr1 = {11, 22, 33, 44, 55, 66, 77, 88, 99};
        int[] arr2 = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    }
}