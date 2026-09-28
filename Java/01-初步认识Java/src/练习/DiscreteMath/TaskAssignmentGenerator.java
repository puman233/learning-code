package 练习.DiscreteMath;

// 纯粹利用数学规律填充 0 和 1 的矩阵
public class TaskAssignmentGenerator implements AssignmentGenerator {

    @Override
    public int[][] generateMatrix(int n) {
        if (n <= 0) {
            return new int[0][0];
        }

        // m = 2^n，代表真值表的总行数（总状态组合数）
        int m = (int) Math.pow(2, n); 
        
        // 声明一个基础二维数组：m 行（状态组合），n 列（变元赋值）
        int[][] matrix = new int[m][n]; 

        // 严格遵循任务书的双重循环交替取反逻辑
        for (int j = 0; j < n; j++) {
            // flag 标志当前格子应该填 1 还是 0
            boolean flag = true; 
            
            // k 代表状态保持不变的行数间隔。例如 3 个变量时，第一列每隔 4 行翻转一次
            int k = (int) Math.pow(2, n - j - 1); 

            for (int i = 0; i < m; i++) {
                // 每当行号 i 能整除间隔 k 时，说明到达了状态翻转点
                if (i % k == 0) {
                    flag = !flag; 
                }

                // 根据布尔标记，在二维数组对应的位置填入 1 或 0
                if (flag) {
                    matrix[i][j] = 1;
                } else {
                    matrix[i][j] = 0;
                }
            }
        }

        return matrix;
    }
}