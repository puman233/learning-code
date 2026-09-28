package Day_11_泛型;

import java.util.List;
// import java.util.ArrayList;

/*
下面是定义泛型方法的规则：

    所有泛型方法声明都有一个类型参数声明部分（由尖括号分隔），
        该类型参数声明部分在方法返回类型之前（在下面例子中的 <E>）。

    每一个类型参数声明部分包含一个或多个类型参数，参数间用逗号隔开。
    一个泛型参数，也被称为一个类型变量，是用于指定一个泛型类型名称的标识符。

    类型参数能被用来声明返回值类型，并且能作为泛型方法得到的实际参数类型的占位符。

    泛型方法体的声明和其他方法一样。注意类型参数只能代表引用型类型，
    不能是原始类型（像 int、double、char 等）.

java 中泛型标记符：

    E - Element (在集合中使用，因为集合中存放的是元素)
    T - Type（Java 类）
    K - Key（键）
    V - Value（值）
    N - Number（数值类型）
    ？ - 表示不确定的 java 类型
 */


/*
因此，泛型就是定义一种模板

例如ArrayList<T>，然后在代码中为用到的类创建对应的ArrayList<类型>
 */
class ArrayList<T>{

    private T[] array;
    private int size;

    // 由于 Java 不允许直接 new T[10]（因为泛型擦除），
    // 通常的做法是创建一个 Object 数组，然后将其强转为 T[]。
    @SuppressWarnings("unchecked")
    public ArrayList(){
        array = (T[]) new Object[10];
        size = 0;
    }
    public void add(T t){
        array[size++] = t;
    }
    public void remove(int index){
        array[index] = null;
    }
    public T get(int index){
        return array[index];
    }
    
    public void printArrayList(){
        for (int i = 0; i < size; i++) {
            System.out.print(array[i] + "\t");
        }
        System.out.println();
    }
}
    


public class _01_泛型 {
    
    // 泛型方法 printArray
    public static < E > void printArray(E[] inputArray) {
        // 输出数组元素
        for (E element : inputArray) {
            System.out.printf("%s ", element);
        }
        System.out.println();
    }

    // 泛型方法 maximum
    // Comparable<T> 是一个接口，定义了 compareTo 方法，用于比较两个对象的大小。
    // 通过实现 Comparable 接口，类可以定义自己的比较逻辑，从而使得对象可以进行排序和比较。
    public static < T extends Comparable<T> > T maximum(T x, T y, T z) {
        T max = x; // 假设 x 是初始最大值
        if (y.compareTo(max) > 0) {
            max = y; //y 更大
        }
        if (z.compareTo(max) > 0) {
            max = z; // z 更大
        }
        return max; // 返回最大对象
    }
    

    public static void main(String args[]) {
        // 创建不同类型数组： Integer, Double 和 Character
        Integer[] intArray = { 1, 2, 3, 4, 5 };
        Double[] doubleArray = { 1.1, 2.2, 3.3, 4.4 };
        Character[] charArray = { 'H', 'E', 'L', 'L', 'O' };

        System.out.println("整型数组元素为:");
        printArray(intArray);   // 传递一个整型数组

        System.out.println("\n双精度型数组元素为:");
        printArray(doubleArray);   // 传递一个双精度型数组

        System.out.println("\n字符型数组元素为:");
        printArray(charArray);   // 传递一个字符型数组


        System.out.printf("\n最大值为 %d\n\n", maximum(3, 4, 5));    // 传递整型参数

        System.out.printf("最大值为 %.1f\n\n", maximum(6.6, 8.8, 7.7));   // 传递双精度型参数

        System.out.printf("最大值为 %s\n", maximum("pear", "apple", "orange"));   // 传递字符串
        
        // ArrayList 的泛型接口为强类型
        ArrayList<String> list = new ArrayList<String>();
        list.add("Hello");
        list.add("World");
        String s1 = list.get(0);
        System.out.println(s1);
        list.printArrayList();

        // 编译器如果能自动推断出泛型类型，就可以省略后面的泛型类型
        ArrayList<Integer> list2 = new ArrayList<>();
        list2.add(1);
        list2.add(2);
        list2.add(3);

        list2.printArrayList();

        ArrayList<Number> list3 = new ArrayList<>();

        list3.add(10);
        list3.add(20.5);
        list3.add(30L);

        list3.printArrayList();
        
    }

}
