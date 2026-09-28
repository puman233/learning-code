package 练习.DiscreteMath;

// 定义变元提取与查找的规范

public interface VariableExtractor {
    
    // 规范 1：传入预处理后的公式，执行提取、去重和排序 (对应 divi 函数)
    void extract(String preprocessedExpr);
    
    // 规范 2：获取提取出来的变元字符数组
    char[] getVariables();
    
    // 规范 3：获取当前公式里有效变元的总数量
    int getVariableCount();
    
    // 规范 4：查找某个字符在变元数组中的下标 (对应 locate 函数)
    int locateVariable(char c);
}