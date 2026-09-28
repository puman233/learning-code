//package Day_06_类.j2_封装;
//
///*
//    private关键字
//        · 是一个权限修饰符
//        · 可以修饰成员（成员变量和成员方法）
//        · 作用是保护成员不被别的类使用，被private修饰的成员只在本类中才能访问
//
//        针对private修饰的成员变量，如果需要被其它类使用，提供相应的操作
//        · 提供 get变量名() 方法，用于获取成员变量的值，方法用public修饰
//        · 提供 set变量名(参数) 方法，用于设置成员变量的值，方法用public修饰
// */
//public class StudentDemo {
//    public static void main(String[] args) {
//        //创建对象
//        Student s = new Student();
//
//        //赋值
//        s.name = "林青霞";
//        s.age = 30;
//
//        s.show();
//    }
//}
//
