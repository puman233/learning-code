package Day_09_集合;

/*
    public boolean remove(Object o); 删除指定的数据
    public E remove(int index);     删除指定索引处的内容
    public E set(int index,E element);  修改指定索引处的元素，返回被修改的元素
    public E get(int index);    返回指定索引处的元素
    public int size();      返回集合中的元素个数
 */

import java.util.ArrayList;

public class j02_ArrayList集合常用方法 {
    public static void main(String[] args) {
        //创建集合
        ArrayList<String> array = new ArrayList<String>();

        //添加元素
        array.add("hello");
        array.add("world");
        array.add("java");

        //public boolean remove(Object o); 删除指定的数据
//        System.out.println(array.remove("world"));
//        System.out.println(array.remove("java"));

        //public E remove(int index);     删除指定索引处的内容
//        System.out.println(array.remove(1));
        //注意：索引不能越界

        //public E set(int index,E element);  修改指定索引处的元素，返回被修改的元素
//        System.out.println(array.set(1,"javaee"));
        //注意：索引不能越界

        //public E get(int index);    返回指定索引处的元素
//        System.out.println(array.get(0));

        //public int size();      返回集合中的元素个数
//        System.out.println(array.size());

        //输出集合
        System.out.println("array:" + array);

    }
}
