package Program;

/*
行政人员包含的信息有：政治面貌、职称等。
class AdminStaff {
        - String politicalStatus
        - String title
    }
 */
public class AdminData extends BasicData {
    private String politicalStatus;
    private String title;

    public AdminData(String id, String name, String gender, int age,  String politicalStatus, String title) {
        super(id, name, gender, age);
        this.title = title;
        this.politicalStatus = politicalStatus;
    }
    public String getTitle() {
        return title;
    }
    public void setTitle(String title) {
        this.title = title;
    }
    public String getPoliticalStatus() {
        return politicalStatus;
    }
    public void setPoliticalStatus(String politicalStatus) {
        this.politicalStatus = politicalStatus;
    }

    @Override
    public String getDetails() {
        return String.format("%s || 编号：%s 姓名：%s 性别：%s 年龄：%s | 政治面貌：%s 职称：%s",
                Staff.formatting("行政人员", 16),
                Staff.formatting(getId(), 6),
                Staff.formatting(getName(), 10),
                Staff.formatting(getGender(), 4),
                Staff.formatting(String.valueOf(getAge()), 5),
                Staff.formatting(getPoliticalStatus(), 18),
                Staff.formatting(getTitle(), 18)
        );
    }
    @Override
    public String toFileString() {
        return String.format("Admin,%s,%s,%s,%d,%s,%s", getId(), getName(), getGender(), getAge(), politicalStatus, title);
    }
}

