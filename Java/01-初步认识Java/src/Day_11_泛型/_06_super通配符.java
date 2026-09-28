package Day_11_泛型;


class ArraryListSupper<T>{
    private T first;
    private T last;

    public ArraryListSupper(T first, T last) {
        this.first = first;
        this.last = last;
    }

    public T getFirst() {
        return first;
    }
    public T getLast() {
        return last;
    }
    public void setFirst(T first) {
        this.first = first;
    }
    public void setLast(T last) {
        this.last = last;
    }
}

/*
<? extends T>允许调用读方法T get()获取T的引用，
    但不允许调用写方法set(T)传入T的引用（传入null除外）；

<? super T>允许调用写方法set(T)传入T的引用，
    但不允许调用读方法T get()获取T的引用（获取Object除外）。

一个是允许读不允许写，另一个是允许写不允许读。
 */

public class _06_super通配符 {

    /*
    和extends通配符相反，
    这次，我们希望接受Pair<Integer>类型，
        以及Pair<Number>、Pair<Object>，
    因为Number和Object是Integer的父类，
    setFirst(Number)和setFirst(Object)实际上允许接受Integer类型。
     */
    static void setSame(ArraryListSupper<? super Integer> p, Integer n) {
        p.setFirst(n);
        p.setLast(n);
    }

    public static void main(String[] args) {

        ArraryListSupper<Number> a1 = new ArraryListSupper<>(12.32, 231.23);
        ArraryListSupper<Integer> a2 = new ArraryListSupper<>(123, 456);

        setSame(a1, 211);
        setSame(a2, 996);

        System.out.println(a1.getFirst() + " " + a1.getLast());
        System.out.println(a2.getFirst() + " " + a2.getLast());

    }


}
