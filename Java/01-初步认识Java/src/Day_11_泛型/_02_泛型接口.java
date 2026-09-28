package Day_11_泛型;

import java.util.Arrays;
import java.lang.Comparable;
// interface Comparable<T> {
//     /**
//      * 返回负数: 当前实例比参数o小
//      * 返回0: 当前实例与参数o相等
//      * 返回正数: 当前实例比参数o大
//      */
//     int compareTo(T o);
// }

/*
泛型接口
除了ArrayList<T>使用了泛型，还可以在接口中使用泛型。

    例如，Arrays.sort(Object[])可以对任意数组进行排序，
    但待排序的元素必须实现Comparable<T>这个泛型接口：
 */



class Person implements Comparable<Person>{
     
    private String name;
    private Integer age;

    Person(String name, Integer age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public int compareTo(Person other) {
        return this.age.compareTo(other.age);
    }

    public String toString() {
        return "Person{name='" + this.name + "', age=" + this.age + "}";
    }
}


public class _02_泛型接口 {

    public static void main(String[] args) {
       
        String[] strArray = {"pear", "apple", "orange"};

        Arrays.sort(strArray);

        for (String str : strArray) {
            System.out.print(str + "\t");
        }

        System.out.println();

        Person[] persons = new Person[] {
                new Person("张三", 20),
                new Person("李四", 18),
                new Person("王五", 22)
        };

        // 若Person类没有实现Comparable接口
        // 会得到ClassCastException，即无法将Person转型为Comparable
        
        Arrays.sort(persons);
        System.out.println(Arrays.toString(persons));


        
        
        
    }

}
