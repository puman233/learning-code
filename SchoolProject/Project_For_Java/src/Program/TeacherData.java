package Program;

import static Program.Staff.formatting;

/*
教师包含的信息有：所在系部、专业、职称；
class Teacher {
        - String department
        - String major
        - String title
    }
 */
public class TeacherData extends BasicData {
    private String department;
    private String major;
    private String title;

    public TeacherData(String id, String name, String gender, int age, String department, String major, String title) {
        super(id, name, gender, age);
        this.department = department;
        this.major = major;
        this.title = title;
    }
    public String getDepartment() {
        return department;
    }
    public void setDepartment(String department) {
        this.department = department;
    }
    public String getMajor() {
        return major;
    }
    public void setMajor(String major) {
        this.major = major;
    }
    public String getTitle() {
        return title;
    }
    public void setTitle(String title) {
        this.title = title;
    }
    // 教师信息
    @Override
    public String getDetails() {
        return String.format("%s || 编号：%s 姓名：%s 性别：%s 年龄：%s | 所在系部：%s 专业：%s 职称：%s",
                formatting("教师", 16),
                formatting(getId(), 6),
                formatting(getName(), 10),
                formatting(getGender(), 4),
                formatting(String.valueOf(getAge()), 5),
                formatting(getDepartment(), 18),
                formatting(getMajor(), 18),
                formatting(getTitle(), 18)
        );
    }
    @Override
    public String toFileString() {
        return String.format("Teacher,%s,%s,%s,%d,%s,%s,%s", getId(), getName(), getGender(), getAge(), department, major, title);
    }
}
