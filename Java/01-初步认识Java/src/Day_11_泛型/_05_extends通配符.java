package Day_11_泛型;

/*
extends通配符的作用

如果我们考察Java标准库的java.util.List<T>接口，
它实现的是一个类似“可变数组”的列表，主要功能包括：

public interface List<T> {
    int size(); // 获取个数
    T get(int index); // 根据索引获取指定元素
    void add(T t); // 添加一个新元素
    void remove(T t); // 删除一个已有元素
}
 */

import java.util.LinkedList;
import java.util.List;
/*
public interface List<T> {
    int size(); // 获取个数
    T get(int index); // 根据索引获取指定元素
    void add(T t); // 添加一个新元素
    void remove(T t); // 删除一个已有元素
}
 */

class ArrayListExtends<T>{
    private T first;
    private T last;

    public ArrayListExtends(T first, T last) {
        this.first = first;
        this.last = last;
    }

    public T getFirst() {
        return first;
    }
    public T getLast() {
        return last;
    }
//    public void setFirst(T first) {
//        this.first = first;
//    }
//    public void setLast(T last) {
//        this.last = last;
//    }
}

// 使用extends限定T类型
// 在定义泛型类型Pair<T>的时候，
// 也可以使用extends通配符来限定T的类型：

class Temp<T extends Number> {

}

public class _05_extends通配符 {

    /*
    允许调用get()方法获取Integer的引用；
    不允许调用set(? extends Integer)方法并传入任何Integer的引用（null除外）
     */
    static int add(ArrayListExtends<? extends Number> p) {
        Number first = p.getFirst();
        Number last = p.getLast();

        // 编译错误！不能写入具体的 Integer
//        p.setFirst(new Integer(first.intValue() + 100));
//        p.setLast(new Integer(last.intValue() + 100));
        return p.getFirst().intValue() + p.getLast().intValue();
    /*
    方法参数类型List<? extends Integer>
        表明了该方法内部只会读取List的元素，
            不会修改List的元素
    因为无法调用add(? extends Integer)、remove(? extends Integer)这些方法
     */
    }

    int sumOfList(List<? extends Integer> list) {
        int sum = 0;
        for (int i=0; i<list.size(); i++) {
            Integer n = list.get(i);
            sum = sum + n;
        }
        return sum;
    }

    public static void main(String[] args) {

        ArrayListExtends<Integer> a = new ArrayListExtends<Integer>(1, 2);

        int n = add(a);

        System.out.println(n);

        List<Integer> integerList = new LinkedList<Integer>();
        integerList.add(10);
        integerList.add(21);
        integerList.add(32);

        _05_extends通配符 main = new _05_extends通配符();
        int sum = main.sumOfList(integerList);
        System.out.println(sum);


    }

}
