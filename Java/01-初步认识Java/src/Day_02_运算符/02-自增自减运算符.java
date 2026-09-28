package Day_02_运算符;

class 自增自减运算符 {
    public static void main(String[] args) {
        /*
        符号          作用          说明
        ++          自增          默认下：变量的值加1
        --          自减          默认下：变量的值减1
         */
        //定义变量
        int a = 10;
        System.out.println("a:" + a);

        //单独使用
        a++;
        ++a;
        System.out.println("a:" + a);

        //参与操作使用
        int k = a++;
        System.out.println("k:" + k);
    }
}
