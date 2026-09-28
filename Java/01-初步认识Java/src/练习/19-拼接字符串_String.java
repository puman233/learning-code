package 练习;

import java.io.StringReader;

class 拼接字符串_String {
    public static void main(String[] args) {
        //定义一个int类型的数组，用静态初始化完成数组元素的初始化
        int[] arr = {1,2,3};

        //调用方法，用一个变量接受结果
        String s = arrayToString(arr);

        //输出结果
        System.out.println("s:" + s);

    }

    //定义一个方法，用于把int数组中的数据中的数据按照指定数据按照指定格式拼接成一个字符串返回

    public static String arrayToString(int[]arr){
        //在方法中遍历数组，按照要求拼接
        String s = "";

        s += "[";

        for (int a=0; a <arr.length; a++){
            if (a == arr.length-1) {
                s += arr[a];
            }else {
                s += arr[a];
                s += "，";
            }
        }

        s += "]";

        return s;
    }
}


class 拼接字符串升级版{
    public static void main(String[] args) {
        int[] arr = {1,2,3};

        String s = arrayToString(arr);

        System.out.println("s" + s);
    }

    public static String arrayToString(int[] arr){
        StringBuilder sb = new StringBuilder();

        sb.append("[");

        for (int i=0;i<arr.length;i++){
            if(i == arr.length-1){
                sb.append(arr[i]);
            } else {
                sb.append(arr[i]).append("，");
            }
        }

        sb.append("]");

        String s = sb.toString();

        return s;
    }
}

