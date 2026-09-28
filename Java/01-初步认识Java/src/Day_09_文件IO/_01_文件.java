package Day_09_文件IO;

/*
Java 文件处理

java.io 包中的 File 文件类允许我们处理文件。
 */

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/*
方法	                类型	    描述
canRead()	            Boolean	    测试文件是否可读
canWrite()	            Boolean	    测试文件是否可写
createNewFile()	        Boolean	    创建一个空文件
delete()	            Boolean	    删除文件
exists()	            Boolean	    测试文件是否存在
getName()	            String	    返回文件名
getAbsolutePath()	    String	    返回文件的绝对路径名
length()	            Long	    返回文件的大小（以字节为单位）
list()	                String[]	返回目录中文件的数组
mkdir()	                Boolean	    创建目录
 */

public class _01_文件 {
    public static void main(String[] args) {

        /*
        创建文件
            使用 createNewFile() 方法。
            此方法返回一个布尔值:
                如果文件创建成功，则返回: true ，
                如果文件已经存在，则返回 false。
            该方法包含在 try...catch 块中。
                因为如果发生错误
                （如果由于某种原因无法创建文件）
                它会抛出 IOException
         */

        try {
//            File newFile = new File("new.txt");
            File newFile = new File("D:\\Files\\Java\\01-初步认识Java\\src\\Day_09_文件IO\\new.txt");
            if (newFile.createNewFile()) {
                System.out.println("文件创建成功：" + newFile.getName());
            } else {
                System.out.println("文件已经存在了");
            }
        } catch (IOException e) {
            System.out.println("发生了错误:" + e.getMessage());
        }

        /*
        写入文件

        FileWriter 类及其 write() 方法
        将一些文本写入我们在上面示例中创建的文件
        完成对文件的写入后，使用 close() 方法关闭它:

         */

        try {
            FileWriter newWrite = new FileWriter("D:\\Files\\Java\\01-初步认识Java\\src\\Day_09_文件IO\\new.txt");
            newWrite.write("写入新的一行");
            newWrite.close();
            System.out.println("成功写入");
        }  catch (IOException e) {
            System.out.println("写入失败：" + e.getMessage());
        }


        /*
        读取文件

            使用Scanner类

            读取完后使用 close() 方法关闭读取流
         */

        try {
            File newRead = new File("D:\\Files\\Java\\01-初步认识Java\\src\\Day_09_文件IO\\new.txt");
            Scanner input = new Scanner(newRead);
            while (input.hasNextLine()) {
                String line = input.nextLine();
                System.out.println("读取文件内容：\n" + "\t" + line);
            }
            input.close();
        } catch (IOException e) {
            System.out.println("读取失败：" + e.getMessage());
        }

        File newRead = new File("D:\\Files\\Java\\01-初步认识Java\\src\\Day_09_文件IO\\new.txt");
        if (newRead.exists()) {
            System.out.println("文件名：" + newRead.getName());
            System.out.println("绝对路径：" + newRead.getAbsolutePath());
            System.out.println("可书写：" + newRead.canWrite());
            System.out.println("可读性：" + newRead.canRead());
            System.out.println("文件大小（字节单位）：" + newRead.length());
        } else {
            System.out.println("该文件不存在");
        }

        /*
        删除文件

            使用delete()方法
         */


        File newDelete = new File("test.txt");
        if (newDelete.delete()) {
            System.out.println("成功删除文件：" + newDelete.getName());
        }
        else {
            System.out.println("删除文件失败");
        }


    }

}
