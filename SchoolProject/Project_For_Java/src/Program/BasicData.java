package Program;

/*
某高校由四类员工：教师、实验员、行政人员、教师兼行政人员：

共有的信息包括：编号、姓名、性别、年龄等。
 class Employee {
        <<abstract>>
        - String id
        - String name
        - String gender
        - int age
        + getters/setters()
        + getDetails()* String
        + toFileString()* String
    }
 */
public abstract class BasicData {
    private String id;
    private String name;
    private String gender;
    private int age;

    BasicData(String id, String name, String gender, int age) {
        this.id = id;
        this.name = name;
        this.gender = gender;
        this.age = age;
    }

    public String getId() {
        return id;
    }
    public void setId(String id) {
        this.id = id;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getGender() {
        return gender;
    }
    public void setGender(String gender) {
        this.gender = gender;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age = age;
    }

    // 获取信息
    public abstract String getDetails();

    // 写入文件信息格式
    public abstract String toFileString();
}
