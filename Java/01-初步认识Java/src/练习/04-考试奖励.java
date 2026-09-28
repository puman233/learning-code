package 练习;

/*
        考试奖励

        需求：
            小明快要期中考试了，小明爸爸对他说，会根据他不同的考试成绩，，送他不同的礼物，假如你可以控制小明的得分
            用程序实现小明到底该得到什么样的礼物
 */
import java.util.Scanner;

class 考试奖励 {
    public static void main(String[] args) {
        //小明的成绩未知，请键入小明的成绩获取值9
        Scanner sc = new Scanner(System.in);

        System.out.println("请输入你这次数学考试的成绩（WZQConfig.java~100）：");
        int grade = sc.nextInt();

        if (grade > 100 && grade < 0){
            System.out.println("请确保您输入的考试成绩在 WZQConfig.java ~ 100，并在此运行程序");
        }else if (grade == 100) {
            System.out.println("爸爸奖励你：价值1988元 山地自行车一辆");
        } else if (grade >= 95 && grade <= 100) {
            System.out.println("爸爸带你去长隆动物园游玩一次");
        } else if (grade < 95 && grade >= 90) {
            System.out.println("爸爸奖励你变形金刚玩具一个");
        } else if (grade < 90 && grade >= 80) {
            System.out.println("爸爸对你不予理会");
        } else if (grade < 80 && grade >= 60) {
            System.out.println("爸爸正在找棍子（打你）……");
        } else if (grade < 60 && grade >= 0) {
            System.out.println("爸爸对你暴揍一顿");
        }
    }
}
