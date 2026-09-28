package Program;

import static Program.Staff.formatting;

/*
教师包含的信息有：所在系部、专业、职称；
行政人员包含的信息有：政治面貌、职称等。

class TeacherAdminStaff {
        - String department
        - String major
        - String teacherTitle
        - String politicalStatus
        - String adminTitle
    }
 */
public class TeacherAdminData extends BasicData {
    private String  department;
    private String  major;
    private String  teacherAdminTitle;
    private String  politicalStatus;

    public TeacherAdminData (String id, String name, String gender, int age, String department, String major, String teacherAdminTitle, String politicalStatus) {
        super(id, name, gender, age);
        this.department = department;
        this.major = major;
        this.teacherAdminTitle = teacherAdminTitle;
        this.politicalStatus = politicalStatus;
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
    public String getPoliticalStatus() {
        return politicalStatus;
    }
    public void setPoliticalStatus(String politicalStatus) {
        this.politicalStatus = politicalStatus;
    }
    public String getTeacherAdminTitle() {
        return teacherAdminTitle;
    }
    public void setTeacherAdminTitle(String teacherAdminTitle) {
        this.teacherAdminTitle = teacherAdminTitle;
    }

    @Override
    public String getDetails() {
        return String.format("%s || 编号：%s 姓名：%s 性别：%s 年龄：%s | 所在系部：%s 专业：%s 政治面貌：%s 职称：%s",
                formatting("教师兼行政人员", 16),
                formatting(getId(), 6),
                formatting(getName(), 10),
                formatting(getGender(), 4),
                formatting(String.valueOf(getAge()), 5),
                formatting(getDepartment(), 18),
                formatting(getMajor(), 18),
                formatting(getPoliticalStatus(), 18),
                formatting(getTeacherAdminTitle(), 18)
        );
    }
    @Override
    public String toFileString() {
        return String.format("TeacherAdmin,%s,%s,%s,%d,%s,%s,%s,%s", getId(), getName(), getGender(), getAge(), department, major, teacherAdminTitle, politicalStatus);
    }
}
