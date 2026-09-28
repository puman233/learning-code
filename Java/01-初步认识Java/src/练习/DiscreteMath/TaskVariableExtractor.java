package 练习.DiscreteMath;

// 这个类只负责纯粹的词法分析与变元管理
public class TaskVariableExtractor implements VariableExtractor {

    // 严格对应任务书中的存储结构
    private char[] myopnd = new char[26]; // 存储不重复的变元 [cite: 13]
    private int varCount = 0;             // 实际记录变元的个数
    
    private ExpressionChecker checker;    // 依赖第一步的检查器来识别运算符

    // 构造方法：注入第一步写好的符号检查器
    public TaskVariableExtractor(ExpressionChecker checker) {
        this.checker = checker;
    }

    @Override
    public void extract(String preprocessedExpr) {
        this.varCount = 0; // 每次提取前清零，防止多次输入数据污染 

        // 遍历公式提取变元并手动去重
        // for(i=0; s[i]!='@'; i++) 
        for (int i = 0; i < preprocessedExpr.length(); i++) {
            char c = preprocessedExpr.charAt(i);
            
            // 遇到结束符 '@' 则直接跳出循环 
            if (c == '@') {
                break;
            }

            boolean isLetter = (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); // 判断是否是英文字母
            
            // 如果不是运算符，说明它是英文字母命题变元 
            if (isLetter && !checker.isOperator(c)) {
                
                // 双重循环手动去重
                // for(t=0; t<j; t++) if(c[t]==s[i]) break; 
                int t;
                for (t = 0; t < varCount; t++) {
                    if (myopnd[t] == c) {
                        break; // 发现了重复的字母，提前跳出 
                    }
                }

                // 如果 t 一直走到了 varCount，说明之前的数组里没有这个字母，属于新变元 
                if (t == varCount) {
                    myopnd[varCount] = c; // 存入数组 
                    varCount++;           // 数量加 1 
                }
            }
        }

        // 基础排序
        // 任务书源码：for(i=0; i<j-1; i++) for(t=i+1; t<j; t++) if(c[i]>c[t]) 
        char aa;
        for (int i = 0; i < varCount - 1; i++) {
            for (int t = i + 1; t < varCount; t++) {
                if (myopnd[i] > myopnd[t]) { // 如果前面的字母 ASCII 码比后面大，就交换 
                    aa = myopnd[i];
                    myopnd[i] = myopnd[t];
                    myopnd[t] = aa;
                }
            }
        }
    }

    @Override
    public char[] getVariables() {
        return this.myopnd;
    }

    @Override
    public int getVariableCount() {
        return this.varCount;
    }

    // 查找下标
    // 严格对照任务书的 locate(char s[], char c) 函数 
    @Override
    public int locateVariable(char c) {
        for (int i = 0; i < varCount; i++) {
            if (myopnd[i] == c) {
                return i; // 找到了，返回变元在数组中的下标 
            }
        }
        return -1; // 没找到返回 -1
    }
}