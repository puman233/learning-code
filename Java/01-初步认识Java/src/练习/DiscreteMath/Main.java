package 练习.DiscreteMath;

import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // 声明的是接口类型，实例化的是具体的任务书处理器
        ExpressionChecker commonChecker = new TaskFormulaPreprocessor();
        VariableExtractor commonExtractor = new TaskVariableExtractor(commonChecker);
        AssignmentGenerator commonAssigner = new TaskAssignmentGenerator();
        

        while (true) {
            System.out.println("\n=============================================");
            System.out.println("   离散数学大作业：命题逻辑系统 (第一步)   ");
            System.out.println("=============================================");
            System.out.println(" 1. 输入命题公式并创建对象 (测试基础初始化)");
            System.out.println(" 2. 退出系统");
            System.out.print(" 请选择操作 (1-2): ");

            String choice = scanner.nextLine().trim();
            if ("2".equals(choice)) {
                System.out.println(" 按下Enter键退出系统...");
                System.out.flush();
                scanner.nextLine(); // 等待用户按下Enter键
                break;
            }

            if ("1".equals(choice)) {
                System.out.print(" 请输入一个命题公式 (如 p&q|!r): ");
                String input = scanner.nextLine();

                // 通过 new 诞生一个实实在在的“公式对象”
                // 把 input 和检查器组件传进去
                PropositionalFormula formula = new PropositionalFormula(input, commonChecker, commonExtractor, commonAssigner);
                
                // 调用公式对象的行为方法，打印出真值表前半部分
                formula.displayAssignmentReport();

                // 展示提取出来的变元列表
                if (formula.getVariableCount() > 0) {
                    System.out.print(" 提取的变元列表: ");
                    for (char var : formula.getVariables()) {
                        System.out.print(var + " ");
                    }
                    System.out.println();
                } else {
                    System.out.println(" 没有提取到任何变元，请检查输入公式是否正确！");
                }
            } else {
                System.out.println(" 输入错误，请输入数字 1 或 2！");
            }
        }
        scanner.close();
    }

    
    
}