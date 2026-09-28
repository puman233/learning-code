package Day_09_集合;

/*
    ArrayList构造方法
        public ArrayList()  创建一个空的集合对象

    ArrayList添加方法：
        public boolean add(E e) 将指定的元素追加到此集合的结尾
        public void add(int index,E element)    在此集合中的指定位置插入指定元素
 */

import java.util.ArrayList;

public class j01_ArrayList {
    public static void main(String[] args) {
        // ArrayList<String> array = new ArrayList<>();
        ArrayList<String> array = new ArrayList<String>();

        // System.out.println(array.add("hello"));

        array.add("hello");
        array.add("world");
        array.add("java");
        array.add("good");

        //第二种插入方法：在指定位置添加
        array.add(1,"javase");
        array.add(3,"javaee");

        System.out.println("array:" + array);
    }
}
