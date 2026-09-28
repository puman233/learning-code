package Program;

/*
导图
Main{
    class BasicData {
        <<abstract>>
        - String id
        - String name
        - String gender
        - int age
        + getters/setters()
        + getDetails()* String
        + toFileString()* String
    }
    class Teacher {
        - String department
        - String major
        - String title
    }
    class LabTechnician {
        - String laboratory
        - String position
    }
    class AdminStaff {
        - String politicalStatus
        - String title
    }
    class TeacherAdminStaff {
        - String department
        - String major
        - String politicalStatus
        - String teacherAdminTitle
    }
    Staff <|-- Teacher
    Staff <|-- LabTechnician
    Staff <|-- AdminStaff
    Staff <|-- TeacherAdminStaff
 }
 */

import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.*;
import java.io.*;

/*
实现功能：
class {
    isID();
    add();
    search();
    display();
    edit();
    delete();
    stats();
    save();
    read();
}
 */
// 程序功能实现
public class Staff{
    // ArrayList集合，存放BasicData数据
    private final ArrayList<BasicData> staff =  new ArrayList<>();

    /*
    System.getProperty(String key, String def)：这是 Java 的标准方法，用于获取系统的属性配置。
        第一个参数是你要查询的“键名”，第二个参数是“默认值（兜底方案）”
        即如果前面那个键不存在或为空，就直接返回这个默认值。
    "sun.stdin.encoding"：这是自 Java 18 开始（包括你正在使用的 JDK 25）JVM 内部非常关键的一个隐藏系统属性。
        它专门用来记录 Java 启动时，自动探测到的宿主操作系统控制台（标准输入 System.in）的真实编码。
    "UTF-8"：当程序运行在一些无法探测到输入编码的环境（或者该属性未定义）时，强制让程序用 UTF-8 作为安全垫。
     */
    // private final Scanner sc = new Scanner(System.in, System.getProperty("sun.stdin.encoding", "UTF-8"));
    // 只要是在打包后的 .exe 真实黑窗口里运行（System.console() 不为空)
    // 就强行让 Scanner 顺从控制台的本地编码（GBK）；
    private final Scanner sc = new Scanner(System.in, System.console() != null ? System.console().charset() : java.nio.charset.StandardCharsets.UTF_8);

    // 文件
    public final String FILE_DATA = "staffData.txt";

    // 判断id是否存在
    public boolean isID (String id) {
        for (BasicData s : staff) {
            if (s.getId().equals(id)) {
                return true;
            }
        }
        return false;
    }

    // 确保输入文件合理化
    private String getString (String tmp) {
        while (true){
            System.out.print(tmp);
            String input = sc.nextLine().trim();
            if (input.isEmpty()){
                System.out.println("输入不能为空，请重新输入");
                continue;
            }
            if (input.contains(",")){
                System.out.println("输入内容包含非法英文逗号[,]，请重新输入");
                continue;
            }
            return input;
        }
    }

    // 确保输入年龄合理化
    private int getInt (String tmp) {
        while (true){
            try {
                int value = Integer.parseInt(getString(tmp));
                if (value < 0 || value > 120) {
                    System.out.println("数据不合理，请重新输入");
                    continue;
                }
                return value;
            } catch (NumberFormatException e) {
                System.out.println("输入年龄非纯数字，请重新输入");
            }
        }
    }

    // 确保编辑id合理化
    private String getEditID(String oldID) {
        while (true){
            System.out.print("请输入新编号 [当前: " + oldID + "]：");
            String input = sc.nextLine().trim();
            if (input.isEmpty()) {
                return oldID; // 直接回车不改编号
            }
            if (input.contains(",")) {
                System.out.println("编号包含非法英文逗号[,]，请重新输入");
                continue;
            }
            if (isID(input) && !input.equals(oldID)) {
                System.out.println("编号冲突，请重新输入");
                continue;
            }
            return input;
        }
    }

    // 确保编辑数据合理化
    private String getEdit (String tmp, String oldValue) {
        while (true){
            System.out.print(tmp + " [当前: " + oldValue + "]：");
            String input = sc.nextLine().trim();
            if (input.isEmpty()){
                return oldValue;    // 空结果返回旧值
            }
            if (input.contains(",")){
                System.out.println("输入内容包含非法英文逗号[,]，请重新输入");
                continue;
            }
            return input;
        }
    }

    // 确保编辑年龄合理化
    private int getEditInt (String tmp, int oldValue) {
        while (true){
            System.out.print(tmp + " [当前: " + oldValue + "]：");
            String input = sc.nextLine().trim();
            if (input.isEmpty()){
                return oldValue;
            }
            try {
                int value = Integer.parseInt(input);
                if (value < 0 || value > 120) {
                    System.out.println("数据不合理，请重新输入");
                    continue;
                }
                return value;
            } catch (NumberFormatException e) {
                System.out.println("输入年龄非纯数字，请重新输入");
            }
        }
    }

    // 添加
    public void addStaff() {
        System.out.println("请输入你要的功能 [0 ~ 4]：");
        System.out.println("数字\t 类型");
        System.out.println("1\t 教师");
        System.out.println("2\t 实验员");
        System.out.println("3\t 行政人员");
        System.out.println("4\t 教师兼行政人员");
        System.out.println("0\t 重选功能\n");

        int input;
        try {
            input = Integer.parseInt(sc.nextLine());
        } catch (Exception e) {
            System.out.println("输入指令有误");
            return;
        }

        if (input == 0) {
            System.out.println("取消此功能");
            return;
        }
        if(input == 1 || input == 2 || input == 3 || input == 4){
            String id = getString("请输入编号：");

            // 信息录入
            if(isID(id)) {
                System.out.println("编号重复，取消录入数据");
            }
            else {
                BasicData Data = null;

                String name = getString("请输入姓名：");
                String gender = getString("请输入性别：");
                int age = getInt("请输入年龄：");

                // 不同人员信息分别录入
                switch (input) {
                    case 1 -> { // 教师
                        String department = getString("请输入所在系部：");
                        String major = getString("请输入专业：");
                        String teacherTitle = getString("请输入职称：");
                        Data = new TeacherData(id, name, gender, age, department, major, teacherTitle);
                    }
                    case 2 -> { // 实验员
                        String laboratory = getString("请输入所在实验室：");
                        String position = getString("请输入职务：");
                        Data = new LabTechData(id, name, gender, age, laboratory, position);
                    }
                    case 3 -> { // 行政人员
                        String politicalStatus = getString("请输入政治面貌：");
                        String adminTitle = getString("请输入职称：");
                        Data = new AdminData(id, name, gender, age, politicalStatus, adminTitle);
                    }
                    case 4 -> { // 教师兼行政人员
                        String teachAdminDepartment = getString("请输入所在系部：");
                        String teachAdminMajor = getString("请输入专业：");
                        String teachAdminTitle = getString("请输入职称：");
                        String teachAdminPoliticalStatus = getString("请输入政治面貌：");
                        Data = new TeacherAdminData(id, name, gender, age, teachAdminDepartment, teachAdminMajor, teachAdminTitle, teachAdminPoliticalStatus);
                    }
                    default -> {
                        System.out.println("输入数据有误");
                    }
                }
                // 录入信息到ArrayList
                if (Data != null) {
                    staff.add(Data);
                    System.out.println("成功添加信息");
                }
            }
        }
        else {
            System.out.println("请输入对应功能的数字");
        }
    }

    // 查询
    public void searchStaff() {
        System.out.println("请输入想要查询的数据： [支持查询：编号、姓名等数据]");
        String input = sc.nextLine().trim();

        if(input.isEmpty()) {
            System.out.println("查询数据不能为空");
            return;
        }

        boolean found = false;
        boolean match;
        for (BasicData s : staff) {
            // 编号、姓名基础数据
            // match = (s.getId().equals(input) || s.getName().equals(input));
            // 改善用contains，模糊搜索
            match = (s.getId().contains(input) || s.getName().contains(input));

            if (match) {
                System.out.println(s.getDetails());
                found = true;
            } else {  // 匹配不同人员的特殊信息
                switch (s) {
                    case TeacherData teacherData -> {
                        // 下转型访问子类的数据
                        if (teacherData.getDepartment().contains(input) || teacherData.getMajor().contains(input) || teacherData.getTitle().contains(input)) {
                            System.out.println(s.getDetails());
                            found = true;
                        }
                    }
                    case AdminData adminData -> {
                        if (adminData.getPoliticalStatus().contains(input) || adminData.getTitle().contains(input)) {
                            System.out.println(s.getDetails());
                            found = true;
                        }
                    }
                    case LabTechData labTechData -> {
                        if (labTechData.getLaboratory().contains(input) || labTechData.getPosition().contains(input)) {
                            System.out.println(s.getDetails());
                            found = true;
                        }
                    }
                    case TeacherAdminData teacherAdminData -> {
                        if (teacherAdminData.getDepartment().contains(input) || teacherAdminData.getMajor().contains(input) || teacherAdminData.getTeacherAdminTitle().contains(input) || teacherAdminData.getPoliticalStatus().contains(input)) {
                            System.out.println(s.getDetails());
                            found = true;
                        }
                    }
                    default -> {
                    }
                }
            }
        }
        if (!found) {
            System.out.println("未查询到该数据");
        }
    }

    // 显示
    public void displayStaff() {
        if (staff.isEmpty()) {
            System.out.println("当前无任何数据");
            return;
        }
        System.out.println("\t所有教职工数据如下:\t");
        for (BasicData s : staff) {
            System.out.println(s.getDetails());
        }
    }

    // 删除
    public void deleteStaff() {
        if (staff.isEmpty()) {
            System.out.println("记录为空！");
            return;
        }

        System.out.println("请输入将要删除人员的编号或名字");
        String input = sc.nextLine().trim();
        // 直接判断能否删除
        boolean isRemoved = staff.removeIf(s -> s.getId().equals(input) || s.getName().equals(input));
        // // 采用迭代器
        // Iterator<BasicData> iterator = staff.iterator();
        // while (iterator.hasNext()) {
        //     BasicData s = iterator.next();
        //     if (s.getId().equals(input) || s.getName().equals(input)) {
        //         iterator.remove();
        //         isRemoved = true;
        //     }
        // }

        if (isRemoved) {
            System.out.println("成功删除该人员记录");
        } else {
            System.out.println("人员记录不存在");
        }
    }

    // 编辑
    public void editStaff() {
        if (staff.isEmpty()) {
            System.out.println("记录为空！");
            return;
        }
        System.out.println("请输入被修改人员的编号：");
        String oldID = sc.nextLine().trim();

        BasicData oldData = null;
        int searchIndex = 0;
        // 记录修改数据在ArrayList中的位置
        for (int i = 0; i < staff.size(); i++) {
            if (staff.get(i).getId().equals(oldID)) {
                oldData = staff.get(i);
                searchIndex = i;
                break;
            }
        }

        if (oldData == null) {
            System.out.println("未找到该编号");
            return;
        }

        System.out.println("该编号人员信息如下：");
        System.out.println(oldData.getDetails());
        System.out.println("请问是否继续编辑该人员信息？");
        System.out.println("0 为否，停止\t 1 为是，继续");
        String input = sc.nextLine().trim();
        if (!(input.equals("1"))) {
            return;
        }

        System.out.println("若不想编辑该信息，直接[回车 · Enter]即可");

        String id = getEditID(oldData.getId());
        String name = getEdit("请输入新姓名", oldData.getName());
        String gender = getEdit("请输入性别", oldData.getGender());
        int age = getEditInt("请输入年龄", oldData.getAge());

        BasicData newData = null;
        // 不同人员信息分别录入
        switch (oldData) {
            case TeacherData teacherData -> {// 教师
                String department = getEdit("请输入所在系部", teacherData.getDepartment());
                String major = getEdit("请输入专业", teacherData.getMajor());
                String teacherTitle = getEdit("请输入职称", teacherData.getTitle());

                newData = new TeacherData(id, name, gender, age, department, major, teacherTitle);
            }
            case LabTechData labTechData -> {// 实验员
                String laboratory = getEdit("请输入所在实验室", labTechData.getLaboratory());
                String position = getEdit("请输入职务", labTechData.getPosition());

                newData = new LabTechData(id, name, gender, age, laboratory, position);
            }
            case AdminData adminData -> {// 行政人员
                String politicalStatus = getEdit("请输入政治面貌", adminData.getPoliticalStatus());
                String adminTitle = getEdit("请输入职称", adminData.getTitle());

                newData = new AdminData(id, name, gender, age, politicalStatus, adminTitle);
            }
            case TeacherAdminData teacherAdminData -> { // 教师兼行政人员
                String teachAdminDepartment = getEdit("请输入所在系部", teacherAdminData.getDepartment());
                String teachAdminMajor = getEdit("请输入专业", teacherAdminData.getMajor());
                String teachAdminTitle = getEdit("请输入职称", teacherAdminData.getTeacherAdminTitle());
                String teachAdminPoliticalStatus = getEdit("请输入政治面貌", teacherAdminData.getPoliticalStatus());

                newData = new TeacherAdminData(id, name, gender, age, teachAdminDepartment, teachAdminMajor, teachAdminTitle, teachAdminPoliticalStatus);
            }
            default -> {
            }
        }
        if (newData != null) {
            staff.set(searchIndex, newData);
            System.out.println("成功修改教职工信息");
        }
    }

    // 统计
    public void statsStaff() {
        int teachCount = 0, adminCount = 0, labTechCount = 0, teachAdminCount = 0;
        int maleCount = 0, femaleCount = 0;

        for (BasicData tmp : staff) {
            if (tmp instanceof TeacherData) {
                teachCount++;
            } else if (tmp instanceof AdminData) {
                adminCount++;
            } else if (tmp instanceof TeacherAdminData) {
                teachAdminCount++;
            } else if (tmp instanceof LabTechData) {
                labTechCount++;
            }
            if (tmp.getGender().equals("男")) {
                maleCount++;
            } else if (tmp.getGender().equals("女")) {
                femaleCount++;
            }
        }

        System.out.println("统计人员信息如下：");
        System.out.println(Staff.formatting(" 类型", 24) + "人数");
        System.out.println(Staff.formatting(" 教师", 24) + teachCount);
        System.out.println(Staff.formatting(" 实验员", 24) + labTechCount);
        System.out.println(Staff.formatting(" 行政人员", 24) + adminCount);
        System.out.println(Staff.formatting(" 教师兼行政人员", 24) + teachAdminCount);
        System.out.println(Staff.formatting(" 性别", 24) + "人数");
        System.out.println(Staff.formatting(" 男员工", 24) + maleCount);
        System.out.println(Staff.formatting(" 女员工", 24) + femaleCount);
        System.out.println(" 【人员总数 ： " + staff.size() + "】");
    }

    // 保存
    public void saveStaff() {
        // 自动备份文件
        File oldFile = new File(FILE_DATA);

        if (oldFile.exists() && oldFile.length() > 0) {
            try {
                // 备份文件夹
                File backupDir = new File("HistoryFiles");
                if (!backupDir.exists()) {
                    backupDir.mkdir();  // 自动创建文件夹
                }

                // 设置文件命名格式
                DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("_yyyy-MM-dd_HH-mm-ss");
                String timeFormatter = LocalDateTime.now().format(dateTimeFormatter);

                // 将备份文件生成到备份文件夹中
                File backupFile = new File(backupDir, oldFile.getName() + timeFormatter + ".txt");

                // 复制文件
                Files.copy(oldFile.toPath(), backupFile.toPath(), StandardCopyOption.REPLACE_EXISTING);

                System.out.println("备份成功，历史数据归档：" + backupFile.getPath());
            } catch (IOException e) {
                System.out.println("备份失败，原因：" + e.getMessage());
            }
        }
        // 保存新文件
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(FILE_DATA))) {
            for (BasicData bdWrite : staff) {
                bw.write(bdWrite.toFileString());
                bw.newLine();
            }
            bw.flush();     // 再刷新一遍数据
            System.out.println("保存数据成功");
        } catch (Exception e) {
            System.out.println("保存失败，原因：" + e.getMessage());
        }
    }

    // 读取
    public void readStaff() {
        File file = new File(FILE_DATA);
        if (!file.exists()) {
            System.out.println("未检测到历史文件");
            return;
        }

        staff.clear();  // 清空内存，重新加载

        int outOfRegexLines = 0;
        int totalLines = 0;

        try (BufferedReader br = new BufferedReader(new FileReader(FILE_DATA))) {
            String line;

            while ((line = br.readLine()) != null) {
                if (line.trim().isEmpty()) {
                    continue;
                }

                try {
                    // 逗号隔开数据
                    String[] tmp = line.split("," , -1);
                    String type = tmp[0];
                    String id = tmp[1];
                    String name = tmp[2];
                    String gender = tmp[3];
                    int age = Integer.parseInt(tmp[4]);
                    switch (type) {
                        case "Teacher" -> {
                            staff.add(new TeacherData(id, name, gender, age, tmp[5], tmp[6], tmp[7]));
                        }
                        case "LabTech" -> {
                            staff.add(new LabTechData(id, name, gender, age, tmp[5], tmp[6]));
                        }
                        case "Admin" -> {
                            staff.add(new AdminData(id, name, gender, age, tmp[5], tmp[6]));
                        }
                        case "TeacherAdmin" -> {
                            staff.add(new TeacherAdminData(id, name, gender, age, tmp[5], tmp[6], tmp[7], tmp[8]));
                        }
                        default -> {
                            outOfRegexLines++;
                        }
                    }
                } catch (Exception e) {
                    // 不符合自定义格式的行数
                    outOfRegexLines++;
                }
                totalLines++;
            }
            System.out.println("本地数据读取成功，共计" + (totalLines - outOfRegexLines) + "行数据");
            if (outOfRegexLines > 0) {
                System.out.println("其中未能识别" + outOfRegexLines + "行数据");
            }

        } catch (IOException e) {
            System.out.println("读取失败，原因：" + e.getMessage());
        }
    }

    // 输出时格式化对齐
    public static String formatting(String str, int totalWidth) {
        if (str == null) str = "";
        int currentWidth = 0;
        for (char ch : str.toCharArray()) {
            // 判断是否为双字节字符（中文、中文标点等）
            if (ch > 127) {
                currentWidth += 2; // 中文在控制台占2个单位格子
            } else {
                currentWidth += 1; // 英文/数字占1个单位格子
            }
        }
        int needSpaces = totalWidth - currentWidth;
        if (needSpaces <= 0) {
            return str;
        }
        // 补齐缺少的空格
        return str + " ".repeat(needSpaces);
    }
}
