package Day_01;

class 算术运算符 {
    public static void main(String[] args) {

    }
}
/*
    算术运算符
WZQConfig.java.1运算符与表达式
    - 运算符:对常量或者变量进行操作的符号
    - 表达式:用运算符吧常量连接起来符合Java语法的式子就可以称之为表达式
            不同运算符连接的表达式体现的是不同类型的表达式
        Eg: + 是运算符,并且是算术运算符
            a + b 是表达式,由于 + 是算术运算符,所以这个表达式叫做算术表达式
*/

class 算术运算符_2{
    public static void main(String[] args){
        //定义变量
        int a = 2;
        int b = 6;

        //进行运算
        System.out.println(a + b);
        System.out.println(a - b);
        System.out.println(a * b);
        System.out.println(b / a);
        System.out.println(a % b); // 取余
    }
}

