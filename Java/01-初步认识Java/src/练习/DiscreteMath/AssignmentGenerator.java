package 练习.DiscreteMath;

// 规范真值指派矩阵的生成行为
public interface AssignmentGenerator {
    
    /**
     * 根据变元个数 n，生成一个 2^n 行 × n 列的真值指派二维矩阵
     * @param variableCount 命题变元的个数
     * @return 存储 0 和 1 的二维基本数组
     */
    int[][] generateMatrix(int variableCount);
}