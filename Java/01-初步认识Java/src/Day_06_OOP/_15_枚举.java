package Day_06_OOP;


enum School {
    TEACHER,
    STUDENT,
    WORKER;
}

public class _15_枚举 {

/*
枚举
    enum 枚举是一个特殊的"类"，
    它表示一组常量（不可更改的变量，如final变量）。

    Enum 是"enumerations"的缩写，意思是"特别列出"。

    要创建enum，请使用enum关键字（而不是类或接口），
    并用逗号分隔常量。

    请注意，它们应为大写字母

枚举和类之间的差异
    enum枚举可以像class类一样具有属性和方法。
    唯一的区别是枚举常量是public, static 和 final
                        （不可更改-无法重写）

    enum 枚举不能用于创建对象，也不能扩展其他类（但可以实现接口）。

    为什么以及何时使用枚举?
    当您知道值不会更改时，如月日期、星期、颜色等，请使用枚举。
 */

    /*
    类内的枚举
        您还可以在类中具有 enum 枚举:
     */
    /*
    枚举构造函数
    枚举(enum)也可以像类一样拥有构造函数。

    构造函数会在常量创建时自动调用。您不能手动调用它。
     */
    enum Level {
        // 枚举常量(每个常量都有自己的描述)
        LOW("Low level"),
        MEDIUM("Medium level"),
        HIGH("High level");

        // 用于存储描述文本的字段(变量)
        private String description;

        // 构造函数(对上述每个常量运行一次)
        // 枚举的构造函数必须是私有的。
        // 如果您不写private，Java 会自动添加。
        private Level(String description) {
            this.description = description;
        }

        // 用于读取描述的 Getter 方法
        public String getDescription() {
            return description;
        }
    }

    public static void main(String[] args) {
        Level myVar = Level.MEDIUM;
        System.out.println(myVar);

        School myschool = School.STUDENT;
        System.out.println(myschool);

        /*
        Switch 语句中的枚举
            枚举通常用于switch语句中检查相应的值:
         */
        switch(myVar) {
            case LOW:
                System.out.println("Low level");
                break;
            case MEDIUM:
                System.out.println("Medium level");
                break;
            case HIGH:
                System.out.println("High level");
                break;
        }

        /*
        循环遍历枚举
            枚举类型有一个 values() 方法，
            该方法返回所有枚举常量的数组。
            如果要循环遍历枚举的常量，此方法非常有用:
         */
        for (Level myLevel : Level.values()) {
            System.out.println(myLevel);
        }

        System.out.println(myVar.getDescription());

        for (Level myLevel : Level.values()) {
            System.out.println(myLevel.getDescription());
        }


    }


}
