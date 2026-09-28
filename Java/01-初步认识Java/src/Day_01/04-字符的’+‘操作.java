package Day_01;

class 字符的_加_操作 {
}

class hello_2{
    public static void main(String[] args){
        //定义两个变量
        int i = 10;
        char c = 'A'; //'A'的值为65
        c = 'a'; //'a'的值为97
        c = '0'; //'0'的值为48
        System.out.println(1 + c);

        //char ch = i + c
        //char类型会被自己提升为 int 类型
        char ch = (char) (i + c);

        int j = 1 + c;
        System.out.println(j);

        //int k = 10 + 13.14;
        double d = 10 + 13.14;
        System.out.println(d);
    }
}

