package Day_12_高级;

import java.util.ArrayList;
import java.util.Collections;

/*
ArrayList 类是一个可以动态修改的数组，
        与普通数组的区别就是它是没有固定大小的限制，
        我们可以添加或删除元素。

ArrayList 继承了 AbstractList ，并实现了 List 接口。

ArrayList 排序
Collections 类位于 java.util 包中，
    提供的 sort() 方法可以对字符或数字列表进行排序。
 */

public class _01_ArrayList {

    public static void main(String[] args) {

        ArrayList<String> list = new ArrayList<>();
        // 添加元素
        list.add("a");
        list.add("b");
        list.add("c");
        list.add("Miku");

        System.out.println(list);

        // 访问元素
        System.out.println(list.get(2));    // index: 3

        // 修改元素
        list.set(1, "Teto");

        System.out.println(list);

        // 删除元素
        list.remove(2);
        System.out.println(list);

        // 计算大小
        System.out.println(list.size());

        for (String L: list) {
            System.out.print(L + "\t");
        }
        System.out.println();

        Collections.sort(list); // 字母排序
        for (String s : list) {
            System.out.print(s + "\t");
        }
        System.out.println();

    }
}

/*
Java ArrayList 方法
Java ArrayList 常用方法列表如下：

方法	        描述
add()	            将元素插入到指定位置的 arraylist 中
addAll()	        添加集合中的所有元素到 arraylist 中
clear()	            删除 arraylist 中的所有元素
clone()	            复制一份 arraylist
contains()	        判断元素是否在 arraylist
get()	            通过索引值获取 arraylist 中的元素
indexOf()	        返回 arraylist 中元素的索引值
removeAll()	        删除存在于指定集合中的 arraylist 里的所有元素
remove()	        删除 arraylist 里的单个元素
size()	            返回 arraylist 里元素数量
isEmpty()	        判断 arraylist 是否为空
subList()	        截取部分 arraylist 的元素
set()	            替换 arraylist 中指定索引的元素
sort()	            对 arraylist 元素进行排序
toArray()	        将 arraylist 转换为数组
toString()	        将 arraylist 转换为字符串
ensureCapacity()	设置指定容量大小的 arraylist
lastIndexOf()	    返回指定元素在 arraylist 中最后一次出现的位置
retainAll()	        保留 arraylist 中在指定集合中也存在的那些元素
containsAll()   	查看 arraylist 是否包含指定集合中的所有元素
trimToSize()    	将 arraylist 中的容量调整为数组中的元素个数
removeRange()   	删除 arraylist 中指定索引之间存在的元素
replaceAll()    	将给定的操作内容替换掉数组中每一个元素
removeIf()      	删除所有满足特定条件的 arraylist 元素
forEach()       	遍历 arraylist 中每一个元素并执行特定操作
 */
