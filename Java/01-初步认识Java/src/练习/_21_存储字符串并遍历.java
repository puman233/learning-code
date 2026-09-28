package 练习;

import java.util.ArrayList;

public class _21_存储字符串并遍历 {
    public static void main(String[] args) {
        //1.创建集合对象
        ArrayList<String> array = new ArrayList<String>();

        //2.放集合中添加字符串对象
        array.add("Tom");
        array.add("Zuo");
        array.add("Fang");

        //3.遍历集合，首先要能够获取集合中的每一个元素，这个通过get(int index)方法实现
//        for (int i = 0;i<3;i++){
//            System.out.println(array.get(i));
//        }
//        System.out.println(array.size());
        //接受元素对象
        for (String s : array) {
            System.out.println(s);
        }
    }
}
