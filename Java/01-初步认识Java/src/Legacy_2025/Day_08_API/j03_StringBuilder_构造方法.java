package Day_08_API;

public class j03_StringBuilder_构造方法 {
    public static void main(String[] args) {
        //public STringBuilder()    创建一个可变字符串对象，不含任何内容
        StringBuilder sb = new StringBuilder();
        System.out.println("sb:"+ sb);
        System.out.println("sb.length():" + sb.length());

        //public StringBuilder(String str)  根据字符串内容，来创建可变字符串对象
        StringBuilder sb2 = new StringBuilder("hello");
        System.out.println("sb2:" + sb2);

    }
}
