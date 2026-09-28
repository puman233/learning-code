package Program;

import static Program.Staff.formatting;

/*
实验员包含的信息有：所在实验室、职务；
class LabTechnician {
        - String laboratory
        - String position
    }
 */
public class LabTechData extends BasicData {
    private String laboratory;
    private String position;

    public LabTechData(String id, String name, String gender, int age, String laboratory, String position) {
        super(id, name, gender, age);
        this.laboratory = laboratory;
        this.position = position;
    }

    public String getLaboratory() {
        return laboratory;
    }
    public void setLaboratory(String laboratory) {
        this.laboratory = laboratory;
    }
    public String getPosition() {
        return position;
    }
    public void setPosition(String position) {
        this.position = position;
    }
    // 获取信息
    @Override
    public String getDetails() {
        return String.format("%s || 编号：%s 姓名：%s 性别：%s 年龄：%s | 所在实验室：%s 职务：%s",
                formatting("实验员", 16),
                formatting(getId(), 6),
                formatting(getName(), 10),
                formatting(getGender(), 4),
                formatting(String.valueOf(getAge()), 5),
                formatting(getLaboratory(), 18),
                formatting(getPosition(), 18)
        );
    }
    @Override
    public String toFileString() {
        return String.format("LabTech,%s,%s,%s,%d,%s,%s", getId(), getName(), getGender(), getAge(), laboratory, position);
    }
}
