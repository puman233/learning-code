package Day_06_OOP;

public class _06_封装 {

/*
    封装
    封装的意义是确保对用户隐藏"敏感"数据。
    要实现这一点，您必须:
        将类变量/属性声明为 private
        提供公共get 和 set方法来访问和更新private 私有变量的值

    Get 和 Set
    只能在同一个类内访问 private私有变量（外部类无权访问它）。
    但是，如果我们提供公共get和set方法，就可以访问它们。
        get方法返回变量值，set方法设置值。
        两者的语法都是以 get 或 set开头，
        后跟变量名，第一个字母大写:


 */
    private String name; // private = restricted access

    // Getter
    public String getName() {
        // get 方法返回变量 name的值。
        return name;
    }

    public int getNameLength() {
        // get 方法返回变量 name的长度。
        return name.length();
    }

    // Setter
    // set 方法接受一个参数(newName) 并将其分配给name变量。
    public void setName(String newName) {
        // this关键字用于引用当前对象。
        this.name = newName;
        // 但是由于name变量声明为private，因此我们无法从此类外部访问它
    }

    public static void main(String[] args) {
        _06_封装 my1 = new _06_封装();

        my1.setName("Miku");
        System.out.println(my1.getName());
        System.out.println(my1.getNameLength());
    }

    /*
封装的意义：
    更好地控制类属性和方法
    类属性可以设置为只读（如果只使用get方法），
        也可以设置为只写（如果只使用set方法）
    灵活:程序员可以在不影响其他部分的情况下更改代码的一部分
    提高数据的安全性
     */


}
