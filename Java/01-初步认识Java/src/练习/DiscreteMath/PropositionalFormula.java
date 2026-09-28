package 练习.DiscreteMath;

public class PropositionalFormula {

    // 对象的私有属性（封装）
    private String rawExpression;          // 用户输入的原始公式
    private String preprocessedExpression;   // 加上了 @ 之后的标准公式 
    
    // 这里依赖的是接口，而不是具体的实现类
    private ExpressionChecker checker;

    // 第二步新增的属性：存储提取出来的变元和变元数量
    private char[] variables;
    private int variableCount;

    // 第三步新增的属性：存储真值指派矩阵和总行数
    private int[][] assignmentMatrix; // 存储全量真值组合的二维数组
    private int totalRows;            // 真值表总行数 (2^n)
    
    // 构造方法：创建一个公式对象
    public PropositionalFormula(String rawExpression, ExpressionChecker checker, VariableExtractor extractor, AssignmentGenerator generator) {
        this.rawExpression = rawExpression;
        this.checker = checker;
        
        // 核心：公式在被 new 出来的时候，自动调用接口的方法给自己完成预处理
        this.preprocessedExpression = this.checker.preprocess(rawExpression);

        // 第二步：执行变元提取与排序 [cite: 11, 12, 13]
        extractor.extract(this.preprocessedExpression);
        this.variableCount = extractor.getVariableCount();

        // 把提取出来的变元存到自己的属性里，方便后续使用（例如展示、后续计算等）
        this.variables = new char[this.variableCount];
        // 直接从 extractor 的 getVariables() 方法里拿到已经提取好的变元数组，复制到自己的属性里
        for (int i = 0; i < this.variableCount; i++) {
            this.variables[i] = extractor.getVariables()[i];
        }

        // 第三步：根据变元数量生成真值指派矩阵
        this.totalRows = (int) Math.pow(2, this.variableCount); // 计算 2^n 的行数
        this.assignmentMatrix = generator.generateMatrix(this.variableCount); // 生成真值指派
    }

    // 外部只能读取（Getter），不能随意篡改
    public String getRawExpression() {
        return rawExpression;
    }

    // 预处理后公式的 Getter 方法
    public String getPreprocessedExpression() {
        return preprocessedExpression;
    }

    // 变元相关的 Getter 方法
    public char[] getVariables() {
        return variables;
    }

    // 变元数量的 Getter 方法
    public int getVariableCount() {
        return variableCount;
    }

    // 真值指派矩阵的 Getter 方法
    public int getTotalRows() {
        return totalRows;
    }

    public int[][] getAssignmentMatrix() {
        return assignmentMatrix;
    }

    // 能够打印出排版整齐的真值表前半部分
    public void displayAssignmentReport() {
        System.out.println("\n=============================================");
        System.out.println("      命题公式状态空间报告 (真值指派生成)      ");
        System.out.println("=============================================");
        System.out.println(" 原始公式: " + this.rawExpression);
        System.out.println(" 变元个数 n = " + this.variableCount + " , 总行数 2^n = " + this.totalRows);
        System.out.println("---------------------------------------------");
        
        // 1. 打印表头（排好序的变量名）
        for (int i = 0; i < this.variableCount; i++) {
            System.out.print(this.variables[i] + "\t");
        }
        System.out.println();
        System.out.println("---------------------------------------------");

        // 2. 嵌套循环打印二维数组里的每一行二进制指派
        for (int i = 0; i < this.totalRows; i++) {
            for (int j = 0; j < this.variableCount; j++) {
                System.out.print(this.assignmentMatrix[i][j] + "\t");
            }
            System.out.println(); // 换行
        }
        System.out.println("=============================================");
    }
}
