package 练习;

class 两只老虎 {
    public static void main(String[] args) {
        /*
        两只老虎

        需求：
            动物园里有两只老虎，已知两只老虎的体重分别是180kg、200kg
            请用Java代码判断两只老虎体重书否相同
         */

        //①定义两个变量用于保存老虎的体重，单位为kg（这里仅仅体现数值即可）
        int tiger1 = 180;
        int tiger2 = 200;

        //②用三元运算符实现老虎体重的判断，体重相同，返回 True，反之则为 False
        boolean b = tiger1 == tiger2 ? true : false;

        //③输出结果
        System.out.println(b);
    }
}
