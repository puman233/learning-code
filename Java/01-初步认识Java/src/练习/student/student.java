package 练习.student;

import java.util.Objects;

public class student {
    private String ID;
    private String Name;
    private String Sex;
    private String Grade;
    public student() {
    }

    public student( String ID,String name, String sex, String grade) {
        Name = name;
        Sex = sex;
        this.ID = ID;
        Grade = grade;
    }

    @Override
    public String toString() {
        return ID + " "  + Name  + " " + Sex  + " " +Grade ;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public String getSex() {
        return Sex;
    }

    public void setSex(String sex) {
        Sex = sex;
    }

    public String getID() {
        return ID;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    public String getGrade() {
        return Grade;
    }

    public void setGrade(String grade) {
        Grade = grade;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        student student = (student) o;
        return Objects.equals(ID, student.ID) &&
                Objects.equals(Name, student.Name) &&
                Objects.equals(Sex, student.Sex) &&
                Objects.equals(Grade, student.Grade);
    }

    @Override
    public int hashCode() {
        return Objects.hash(ID, Name, Sex, Grade);
    }
}