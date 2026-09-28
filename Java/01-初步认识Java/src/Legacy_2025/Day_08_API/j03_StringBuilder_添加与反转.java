package Day_08_API;

/*
    StringBuilder构造方法
        public StringBuilder append(任意类型)，添加数据，并返回对象本身
        public StringBuilder reverse()，返回相反的字符序列
 */

public class j03_StringBuilder_添加与反转 {
    public static void main(String[] args) {
        //创建对象
        StringBuilder sb = new StringBuilder();

        //public StringBuilder append(任意类型)，添加数据，并返回对象本身
        StringBuilder sb2 = sb.append("hello");
        System.out.println("sb: "+ sb);
        System.out.println("sb2: "+ sb2);
        System.out.println(sb == sb2);

        sb.append("hello");
        sb.append("world");
        sb.append("java");
        sb.append(100);
        System.out.println("sb:"+sb);

        //链式编程
        sb.append("hello").append("world").append("java").append(100);
        System.out.println("sb:"+sb);

        //public StringBuilder reverse()，返回相反的字符序列
        sb.reverse();
        System.out.println("sb:"+sb);

        System.out.println("-----分割线-----");
        //打印正序
        StringBuilder java = new StringBuilder();
        StringBuilder java2 = java.append("hello");
        System.out.println("java:"+java);
        System.out.println("java2:"+java2);
        System.out.println(java == java2);


    }
}
