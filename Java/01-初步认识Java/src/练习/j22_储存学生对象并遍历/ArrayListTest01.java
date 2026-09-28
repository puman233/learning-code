package 练习.j22_储存学生对象并遍历;

import java.util.ArrayList;

public class ArrayListTest01 {
    public static void main(String[] args) {
        //创建集合对象
        ArrayList<Student> array = new ArrayList<Student>();

        //创建学生对象
        Student s1 = new Student("Tom",30);
        Student s2 = new Student("Amy",20);
        Student  s3 = new Student("Bob",30);

        //添加学生对象到集合中
        array.add(s1);
        array.add(s2);
        array.add(s3);

        //便利集合，采用通用便利格式实现
        for (Student s : array) {
            System.out.println(s.getName() + "，" + s.getAge());
        }
    }
}
