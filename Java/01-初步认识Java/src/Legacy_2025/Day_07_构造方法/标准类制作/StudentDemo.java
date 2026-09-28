package Day_07_构造方法.标准类制作;

public class StudentDemo {
    public static void main(String[] args) {
        //无参构造方法创建对象后使用setXxx()赋值
        Student s1 = new Student();
        s1.setAge(30);
        s1.setName("Python");
        s1.show();

        //使用带参构造方法直接创建带有属性值的对象
        Student s2 = new Student("Python",30);
        s2.show();
    }
}
