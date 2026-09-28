package Day_07_异常;

import java.io.*;
// public class IOException
// extends Exception

import java.util.*;
import java.io.IOException;

/*
throws/throw 关键字
    在Java中， throw 和 throws 关键字是用于处理异常的。

    throw 关键字用于在代码中抛出异常，
    throws 关键字用于在方法声明中指定可能会抛出的异常类型。

    throw 关键字用于在当前方法中抛出一个异常。
    通常情况下，当代码执行到某个条件下无法继续正常执行时，
    可以使用 throw 关键字抛出异常，以告知调用者当前代码的执行状态。

    throws 关键字用于在方法声明中指定该方法可能抛出的异常。
    当方法内部抛出指定类型的异常时，该异常会被传递给调用该方法的代码，并在该代码中处理异常。

finally关键字
    finally 关键字用来创建在 try 代码块后面执行的代码块
    无论是否发生异常，finally 代码块中的代码总会被执行
    在 finally 代码块中，可以运行清理类型等收尾善后性质的语句
    finally 代码块出现在 catch 代码块最后

    try{
      // 程序代码
    }catch(异常类型1 异常的变量名1){
      // 程序代码
    }catch(异常类型2 异常的变量名2){
      // 程序代码
    }finally{
      // 程序代码
    }
 */

public class _02_throws_finally {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("只有 0 抛出异常");
        int n = sc.nextInt();

        // 代码块抛出异常
        check c = new check();
        c.checkNum(n);

        System.out.println("test Completion");

        String s1, s2;
        s1 = "D:\\text.txt";
        s2 = "D:\\Files\\Java\\01-初步认识Java\\src\\Day_07_异常\\text.txt";

        System.out.println("1 为error，2为true");
        n =  sc.nextInt();

        // throws 方法抛出异常
        try {
            if (n==1){
                c.readFile(s1);
            }
            else if (n == 2){
                c.readFile(s2);
            }
        } catch (IOException e1) {
            /*
            public String getMessage()
                返回关于发生的异常的详细信息。
                这个消息在Throwable 类的构造函数中初始化了。
             */
            System.out.println("IOException:文件读取失败;" + e1.getMessage());
        }

        System.out.println("test Completion");

        // finally 关键字
        int[] arr = new int[2];
        try {
            System.out.println("输出第4个数：" + arr[3]);
        } catch (ArrayIndexOutOfBoundsException e2) {
            System.out.println("抛出异常：" + e2.getMessage());
        } finally {
            arr[1] = 2;
            System.out.println("第2个数为：" + arr[1]);
        }
        System.out.println("test Completion");

    }

}

class check {

    public void checkNum (int num){
        if(num == 0){
            throw new ArithmeticException();
        }

    }

    // 文件操作,ai注释
    // 当 readFile 方法内部发生 IOException 异常时，会将该异常传递给调用该方法的代码
    // 在调用该方法的代码中，必须捕获或声明处理 IOException 异常。
    public void readFile(String filePath) throws IOException {
        // 创建 BufferedReader 对象，用于按“行”读取文本文件
        // BufferedReader 属于缓冲字符输入流，读取效率较高
        // FileReader 用于连接指定路径的文件
        // filePath 是文件路径，例如："D:\\test.txt"
        BufferedReader reader = new BufferedReader(new FileReader(filePath));

        // 读取文件中的第一行内容
        // readLine() 方法每调用一次，就会读取一行数据
        // 返回值类型是 String
        // 如果读取到文件末尾，则返回 null
        String line = reader.readLine();

        // 判断当前读取的内容是否为空
        // 只要 line != null，说明还有数据可以继续读取
        while (line != null) {

            System.out.println(line);

            // 继续读取下一行内容
            // 如果不写这一句，line 的值永远不会变化
            // 会导致 while 循环无限执行，形成死循环
            line = reader.readLine();
        }

        // 文件读取完成后关闭流对象
        // close() 的作用是释放系统资源
        // 不关闭流可能导致：
        // 1. 内存浪费
        // 2. 文件被占用
        // 3. 程序性能下降
        reader.close();

    }

}


