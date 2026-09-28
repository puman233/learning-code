package Program;

import java.util.Scanner;
/*
高校人员信息管理系统
某高校由四类员工：教师、实验员、行政人员、教师兼行政人员：

共有的信息包括：编号、姓名、性别、年龄等。
    教师包含的信息有：所在系部、专业、职称；
    实验员包含的信息有：所在实验室、职务；
    行政人员包含的信息有：政治面貌、职称等。

功能要求：
1）添加功能：能够任意添加上述四类人员的记录，要求员工的编号要唯一，
            如果添加了重复编号的记录时，则提示数据添加重复并取消添加。
2）查询功能：可根据编号、姓名等信息对已添加的记录进行查询，
            如果未找到，则给出相应的提示信息，如果找到，则显示相应的记录信息。
3）显示功能：可显示当前系统中所有的记录，每条记录占据一行。
4）编辑功能：可根据查询结果对相应的记录进行修改，修改时注意编号的唯一性。
5）删除功能：对已添加的人员记录进行删除。
            如果当前系统中没有相应的人员记录，则提示“记录为空！”并返回操作；
            否则，输入要删除的人员的编号或姓名，根据所输入的信息删除该人员记录，
            如果没有找到该人员信息，则提示相应的记录不存。
6）统计功能：能根据多种参数进行人员的统计。
            能统计四类人员数量以及总数，统计男、女员工的数量。
7）保存功能：可将当前系统中各类人员记录存入文件中。
8）读取功能：可将保存在文件中的人员信息读入到当前系统中，供用户进行使用。

 */
/*
终端命令：
打包jar

    jar cfe StaffSystem.jar Program.Main -C out/production/你的项目名/ .

    c (Create)：代表创建新的 JAR 文件。
    f (File)：代表指定生成的 JAR 文件名（这里叫 StaffSystem.jar）
    e (Entry-point)：代表指定程序的执行入口，也就是包含 main 方法的完整类名
                    （代码中 Program.Main）

    -C out/production/你的项目名/.
        它表示先切换到编译输出目录，然后把里面的所有内容打包
        （ . 代表当前目录下的所有文件）

jar cfe jar/StaffSystem.jar Program.Main -C out/production/Project/ .


打包 exe

示例：
    jpackage --type app-image --name StaffSystem --input out/artifacts/你的项目jar包所在目录 --main-jar 你的项目名.jar --main-class Program.Main --win-console --runtime-image "C:\Program Files\Java\jdk-25.0.2"

jpackage --type app-image --name StaffSystem --input jar/ --main-jar StaffSystem.jar --main-class Program.Main --win-console --runtime-image "C:\Program Files\Java\jdk-25.0.2"

 */
// 入口
public class Main {

    public static void main(String[] args) {
        Staff staff = new Staff();

        // 读取历史数据
        staff.readStaff();

        Scanner sc = new Scanner(System.in);
        while(true) {
            System.out.println();
            System.out.println("输入数字[0 ~ 8]以实现功能：");
            System.out.println("数字\t 功能");
            System.out.println("0\t 退出系统");
            System.out.println("1\t 添加人员信息");
            System.out.println("2\t 查询人员信息");
            System.out.println("3\t 显示所有人员信息");
            System.out.println("4\t 编辑人员信息");
            System.out.println("5\t 删除人员信息");
            System.out.println("6\t 统计人员信息");
            System.out.println("7\t 保存人员信息");
            System.out.println("8\t 读取人员信息\n");

            try {
                String choice = sc.nextLine().trim();
                switch (choice) {
                    case "0" -> {
                        System.out.println("自动保存数据中...");
                        staff.saveStaff();
                        System.out.println("数据已保存，系统已退出，请按 [Enter · 回车] 键关闭控制台...");
                        sc.nextLine();

                        sc.close(); // 关闭Scanner流
                        System.exit(0);
                    }
                    case "1" -> staff.addStaff();
                    case "2" -> staff.searchStaff();
                    case "3" -> staff.displayStaff();
                    case "4" -> staff.editStaff();
                    case "5" -> staff.deleteStaff();
                    case "6" -> staff.statsStaff();
                    case "7" -> staff.saveStaff();
                    case "8" -> staff.readStaff();
                    default -> System.out.println("输入数据有误，请输入[0 ~ 8]的数字");
                }
            } catch (Exception e) {
                System.out.println("输入数据错误，原因：" + e.getMessage());
            }
        }
    }
}
