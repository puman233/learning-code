package Day_04_数组;

class 数组_2 {
    public static void main(String[] args) {
        @SuppressWarnings("unused")
        int[] arr = new int[3];
        /*
            左边
                int:说明数组中的元素类型是int类型
                []:说明这是一个数组
                arr:这是数组的名称

            右边
                new:为数组申请内存空间
                int:说明数组中的元素类型是int类型
                []:说明这是一个数组
                3:数组长度，其实就是数组中的元素个数
         */

        int[][] myNumbers = { {1, 4, 2}, {3, 6, 8} };

        System.out.println(myNumbers[0][1]); // 输出 4
        for(int E[] : myNumbers){
            for(int e: E){
                System.out.print(e + " ");
            }
            System.out.println(); // 换行
        }
        for(int i = 0; i < myNumbers.length; i++){
            for(int j = 0; j < myNumbers[i].length; j++){
                System.out.print(myNumbers[i][j] + " ");
            }
            System.out.println(); // 换行
        }
    }
}
