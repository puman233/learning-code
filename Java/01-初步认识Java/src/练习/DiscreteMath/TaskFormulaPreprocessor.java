package 练习.DiscreteMath;


// 这个类只负责纯粹的符号判定和字符串末尾拼接
public class TaskFormulaPreprocessor implements ExpressionChecker {

    // 任务书规定的 8 个运算符 
    private static final String OPTR_LIST = "+-|&!()@";

    @Override
    public boolean isOperator(char c) {

        // 纯基础语法：用一个简单的 for 循环，挨个比对字符
        for (int i = 0; i < OPTR_LIST.length(); i++) {
            if (c == OPTR_LIST.charAt(i)) {
                return true; // 找到了，说明是运算符 
            }
        }
        return false; // 循环走完没找到，说明不是运算符 
    }

    @Override
    public String preprocess(String rawExpression) {

        // t=strlen(s); s[t]='@'; s[t+1]='\0'; 
        // 基础语法实现：去掉前后空格，并在末尾直接拼接 '@' 字符 
        if (rawExpression == null) {
            rawExpression = ""; // 防止输入为 null 导致异常 
            return "@"; // 直接返回只有结束符的字符串
        }
        String noSpaceExpression = rawExpression.trim(); // 去掉前后空格
        return noSpaceExpression + "@"; // 拼接结束符并返回
    }

}
