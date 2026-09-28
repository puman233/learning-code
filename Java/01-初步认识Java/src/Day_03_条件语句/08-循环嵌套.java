package Day_03_条件语句;

class 循环嵌套 {
    public static void main(String[] args) {
        /*
            循环嵌套：
                循环语句中包含循环语句
            需求：
                输出一天的小时和分钟

                分钟和小时的范围：
                    分钟： 0 <= minute < 60
                    小时： 0 <= hour < 24
         */

        //循环改进V1.0
        for (int hour = 0; hour < 24; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                System.out.println(hour + "时" + minute + "分");
            }
        }

        System.out.println("------------------");

        //循环语句增强版（循环改进V2.0）
        for (int hour2 = 0; hour2 < 24; hour2++) {
            for (int minute2 = 0; minute2 < 60; minute2++) {
                for (int second = 0; second < 60; second++) {
                    System.out.println(hour2 + "时" + minute2 + "分" + second + "秒");
                }
            }
        }
    }
}
