package Day_04_数组;

class 数组_1 {
    public static void main(String[] args) {
        /*
            数组的定义格式

                格式一：
                    数据类型[] 变量名
                    范例： int[] arr
                    定义了一个int类型的数组，数组名是arr

                格式二：
                    数据类型 变量名[]
                    范例： int arr[]
                    定义了一个int类型的变量，变量名是arr数组
         */

        int [] arr = new int[3]; // 定义了一个int类型的数组，数组名是arr
        int arr2[] = new int[3]; // 定义了一个int类型的数组，数组名是arr2
        for ( int E : arr ) {
            System.out.println(E);
        }
        for (int i = 0; i < arr.length; i++){
            System.out.println(arr[i]);
        }
        for (int i = 0; i < arr2.length; i++){
            System.out.println(arr2[i]);
        }
    }
}
