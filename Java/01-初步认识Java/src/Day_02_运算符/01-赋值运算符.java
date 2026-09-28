package Day_02_运算符;

class 赋值运算符{
    public static void main(String[]args){
        //把10赋值给int类型的变量a
        int i = 10;
        System.out.println("i:" + i);

        //+= 把左边和和右边的数据做加法操作，结果赋值给左边
        i += 20;
        System.out.println("i:" + i);

        //注意：
        short a = 10;
        a += 20;
        a = (short)(a +20);
        System.out.println("a:" + a);
        

        /*
        符号          作用          说明
        =           赋值          a=10，将10赋值给变量a
        +=          加后赋值       a+=b，将a+b的和给a
        -=          减后赋值       a-=b，将a-b的差给a
        *=          乘后赋值       a*=b，将a*b的积给a
        /=          除后赋值       a/=b，将a/b的商给a
        %=          取余后赋值      a%=b，将a/b的余数给a
         */
    }
}
