package Day_11_泛型;

/*
泛型是一种类似”模板代码“的技术，不同语言的泛型实现方式不一定相同。

Java语言的泛型实现方式是擦拭法（Type Erasure）。
    所谓擦拭法是指，虚拟机对泛型其实一无所知，所有的工作都是编译器做的。

Java使用擦拭法实现泛型，导致了：
    编译器把类型<T>视为Object；
    编译器根据<T>实现安全的强制转型。


使用泛型的时候，我们编写的代码也是编译器看到的代码：
    Pair<String> p = new Pair<>("Hello", "world");
    String first = p.getFirst();
    String last = p.getLast();

而虚拟机执行的代码并没有泛型：
    Pair p = new Pair("Hello", "world");
    String first = (String) p.getFirst();
    String last = (String) p.getLast();

Java的泛型是采用擦拭法实现的；

擦拭法决定了泛型<T>：

    不能是基本类型，例如：int；
    不能获取带泛型类型的Class，例如：Pair<String>.class；
    不能判断带泛型类型的类型，例如：x instanceof Pair<String>；
    不能实例化T类型，例如：new T()。
    泛型方法要防止重复定义方法，例如：public boolean equals(T obj)；

子类可以获取父类的泛型类型<T>。
 */

/*
局限一：<T>不能是基本类型
    例如int，因为实际类型是Object，Object类型无法持有基本类型：
    Pair<int> p = new Pair<>(1, 2); // compile error!
 */

/*
局限二：无法取得带泛型的Class
 */
class Pair3<T> {
    private T first;
    private T last;
    public Pair3(T first, T last) {
        this.first = first;
        this.last = last;
    }
    public T getFirst() {
        return first;
    }
    public T getLast() {
        return last;
    }
    /*
    局限四：不能实例化T类型：
     */
//    public Pair3(){
//        first = new T();
//        last = new T();
//    }

    // 要实例化T类型，我们必须借助额外的Class<T>参数
    public Pair3(Class<T> clazz, T first, T last) {
        this.first = clazz.cast(first);
        this.last = clazz.cast(last);
    }
}

public class _04_擦拭法 {

    public static void main(String[] args) {

        /*
        因为T是Object，我们对Pair<String>和Pair<Integer>类型获取Class时，
            获取到的是同一个Class，也就是Pair类的Class
         */
        Pair3<String> p1 = new Pair3<>("Hello", "world");
        Pair3<Integer> p2 = new Pair3<>(123, 456);
        Class c1 = p1.getClass();
        Class c2 = p2.getClass();
        System.out.println(c1==c2); // true
        System.out.println(c1==Pair3.class); // true

        /*
        局限三：无法判断带泛型的类型：

            Pair<Integer> p = new Pair<>(123, 456);
            // Compile error:
            if (p instanceof Pair<String>) {
            }
         */

    }

}
