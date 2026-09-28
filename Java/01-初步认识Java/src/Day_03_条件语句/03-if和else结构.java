package Day_03_条件语句;

class if和else结构 {
    public static void main(String[] args) {
        System.out.println("开始");

        //定义两个变量
        int a = 10;
        int b = 20;

        //需求：判断a是否大于b
        if(a > b){
            System.out.println("a的值大于b");
        }

        //需求：判断a是否小于b
        if(a < b){
            System.out.println("a的值小于b");
        }
    }
}
