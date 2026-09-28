package Day_11_泛型;

// 编写普通类
/*
class Pair {
    private String first;
    private String last;
    public Pair(String first, String last) {
        this.first = first;
        this.last = last;
    }
    public String getFirst() {
        return first;
    }
    public String getLast() {
        return last;
    }
}

 */

/*
泛型类
泛型类的声明和非泛型类的声明类似，除了在类名后面添加了类型参数声明部分。

    泛型类的类型参数声明部分也包含一个或多个类型参数，
    参数间用逗号隔开。

    一个泛型参数，也被称为一个类型变量，
    是用于指定一个泛型类型名称的标识符。

    因为他们接受一个或多个参数，
    这些类被称为参数化的类或参数化的类型。
 */

import java.lang.reflect.Type;

// 标记所有的特定类型，这里是String，把特定类型String替换为T，并申明<T>
class Pair<T> {
    private T first;
    private T last;

    public Pair(T first, T last) {
        this.first = first;
        this.last = last;
    }

    public T getFirst() {
        return first;
    }

    public T getLast() {
        return last;
    }

    // 静态方法
    //编写泛型类时，要特别注意，泛型类型<T>不能用于静态方法
//    public static Pair<T> create(T first, T last) {
//        return new Pair<T>(first, last);
//    }
    // 上述代码会导致编译错误，
    // 我们无法在静态方法create()的方法参数和返回类型上使用泛型类型T

    // 对于静态方法，我们可以单独改写为“泛型”方法，
    // 只需要使用另一个类型即可
    // 静态泛型方法应该使用其他类型区分:
    public static <K> Pair<K> create(K first, K last) {
        return new Pair<K>(first, last);
    }
}

class Box<T> {
    private T t;
    public Box(T t) {
        this.t = t;
    }

    public T getT() {
        return t;
    }
}

// 多个泛型类型
class Array<T, K>{
    private T[] t;
    private K[] k;
    public Array(T[] t, K[] k) {
        this.t = t;
        this.k = k;
    }

    public void printT() {
        for (T value : t) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
    public void printK() {
        for (K value : k) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
}


public class _03_泛型类 {

    public static void main(String[] args) {

        Pair<String> pair1 = Pair.create("a", "b");
        Pair<String> pair2 = Pair.create("Hello", "World");
        System.out.println(pair1.getFirst());
        System.out.println(pair2.getLast());

        Box<Integer> integerBox = new Box<Integer>(5);
        Box<String> stringBox = new Box<String>("Hello");

        Integer integer1 = integerBox.getT();
        String string1 = stringBox.getT();

        System.out.println(integer1);
        System.out.println(string1);

        String[] names = new String[]{
                "Miku",
                "Teto"
        };

        Integer[] integerArray = new Integer[]{
                18,
                31
        };

        Array<String, Integer> array = new Array<>(names, integerArray);

        array.printT();
        array.printK();


    }

}
