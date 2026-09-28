package 练习.DiscreteMath;

// 只定义规范
public interface ExpressionChecker {
    // 规范 1：判断字符 c 是不是任务书规定的运算符
    boolean isOperator(char c);
    
    // 规范 2：对输入的原始公式进行预处理（例如任务书要求的加 @ 结束符）
    String preprocess(String rawExpression);

}
