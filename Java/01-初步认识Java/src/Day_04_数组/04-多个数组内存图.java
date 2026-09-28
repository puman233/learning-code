package Day_04_数组;

class 多个数组内存图 {
    public static void main(String[] args) {
        //定义两个数组
        int[] arr = new int[2];
        int[] arr2 = new int[3];

        //分别输出数组名及数据
        System.out.println(arr);
        System.out.println(arr[0]);
        System.out.println(arr[1]);

        System.out.println(arr2);
        System.out.println(arr2[0]);
        System.out.println(arr2[1]);

        //然后再次分别输出数组名及数据
        arr[0] = 100;
        arr2[0] = 200;
        arr2[1] = 300;

        //分别再次输出数组名及元素
        System.out.println(arr);
        System.out.println(arr[0]);
        System.out.println(arr[1]);

        System.out.println(arr2);
        System.out.println(arr2[0]);
        System.out.println(arr2[1]);

    }
}
