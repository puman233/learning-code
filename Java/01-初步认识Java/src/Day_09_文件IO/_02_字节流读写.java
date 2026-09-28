package Day_09_文件IO;

/*
Byte 字节流
    处理原始二进制数据(例如图像、音频和 PDF 文件)。
    示例:FileInputStream、FileOutputStream。
 */

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class _02_字节流读写 {

    public static void main(String[] args) {

        try {
            FileInputStream newInput = new FileInputStream("D:\\Files\\Java\\01-初步认识Java\\src\\Day_09_文件IO\\Bytes.txt");

            int i;  // 存储每个字节
            // 一次读取一个字符，直到末尾（-1,后无数据）
            while ((i = newInput.read()) != -1) {
                System.out.print((char) i);
            }

            newInput.close();
        }catch (IOException e){
            System.out.println("读取文件失败：" + e.getMessage());
        }

        System.out.println();
        /*
        复制二进制文件
            FileInputStream 的真正优势在于它可以处理任何文件类型，而不仅仅是文本文件
             由于它处理的是原始字节，
             因此可以复制任何类型的文件——文本、图像、音频或 PDF。
         */
        try {
            FileInputStream input = new FileInputStream("image.jpg");
            FileOutputStream output = new FileOutputStream("copy.jpg");

            int i;

            while ((i = input.read()) != -1) {
                System.out.print((char) i);
            }

            input.close();
            output.close();

            System.out.println("复制成功");
        } catch (IOException e) {
            System.out.println("处理文件失败：" + e.getMessage());
        }

        /*
        FileOutputStream 类的工作方式类似，但它以原始字节的形式写入数据

        也可以复制文件

        注意:如果文件已存在，其内容将被替换(覆盖)。

         */

        String text = "Hello World!";

        // try-with-resources:流将自动关闭
        try (FileOutputStream output = new FileOutputStream("D:\\Files\\Java\\01-初步认识Java\\src\\Day_09_文件IO\\Bytes.txt")) {
            output.write(text.getBytes());  // 将文本转换为字节并写入
            System.out.println("成功提交文件。");

            FileInputStream input = new FileInputStream("D:\\Files\\Java\\01-初步认识Java\\src\\Day_09_文件IO\\Bytes.txt");
            int i;
            System.out.println("写入内容如下：");
            while ((i = input.read()) != -1) {
                System.out.print((char) i);
            }
            System.out.println();
            input.close();
        } catch (IOException e) {
            System.out.println("写入文件错误。" + e.getMessage());
        }

        /*
        追加到文件
            默认情况下，FileOutputStream 会覆盖 已存在的文件。
            要改为添加(追加) 新内容，请将 true 作为第二个参数传递:
         */

        String appendText = "Next Line";

        // true = append mode (keeps existing content)
        try (FileOutputStream output = new FileOutputStream("D:\\Files\\Java\\01-初步认识Java\\src\\Day_09_文件IO\\Bytes.txt", true)) {
            output.write(text.getBytes());
            System.out.println("成功附加到文件中");
        } catch (IOException e) {
            System.out.println("写入文件错误" + e.getMessage());
        }


    }
}
