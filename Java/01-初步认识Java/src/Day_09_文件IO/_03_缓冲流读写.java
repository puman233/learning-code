package Day_09_文件IO;

/*
BufferedReader 和 BufferedWriter 可以加快文本文件的读写速度。

    BufferedReader 可以使用 readLine() 逐行读取文本。
    BufferedWriter 可以使用 newLine() 高效地写入文本并添加新行。
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.File;
import java.io.IOException;

public class _03_缓冲流读写 {
    public static void main(String[] args){

        // 创建文件
        try {
            File newFile = new File("D:\\Files\\Java\\01-初步认识Java\\src\\Day_09_文件IO\\buffer.txt");
            if (newFile.createNewFile()) {
                System.out.println("成功创建");
            } else {
                System.out.println("创建失败");
            }
        } catch (IOException e) {
            System.out.println("出错：" + e.getMessage());
        }

        System.out.println();

        // 读取文件
        try (BufferedReader br = new BufferedReader(new FileReader("D:\\Files\\Java\\01-初步认识Java\\src\\Day_09_文件IO\\buffer.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.out.println("读取错误文件" + e.getMessage());
        }

        System.out.println();

        /*
        BufferedWriter
            BufferedWriter 类用于一次写入一行或一个字符串到文件中。
            如果文件已存在，则会替换(覆盖)其内容。

            使用 BufferedWriter 和 FileWriter 向文件中写入文本。
            write() 方法用于添加文本，
            使用 newLine() 插入换行符。
         */

        try (BufferedWriter bw = new BufferedWriter(new FileWriter("D:\\Files\\Java\\01-初步认识Java\\src\\Day_09_文件IO\\buffer.txt"))) {
            bw.write("第一行");
            bw.newLine();  // 添加换行
            bw.write("第二行");
            System.out.println("成功写入文件");
        } catch (IOException e) {
            System.out.println("写入文件错误" + e.getMessage());
        }

        System.out.println();
        /*
        追加到文本文件
            要将新内容添加到文件末尾(而不是覆盖原有内容)，
            请将 true 传递给 FileWriter
         */

        // true = append mode
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("D:\\Files\\Java\\01-初步认识Java\\src\\Day_09_文件IO\\buffer.txt", true))) {
            bw.newLine();                      // 移到新行
            bw.write("附加行");         // 在末尾添加新文本
            System.out.println("成功附加到文件中");

            BufferedReader br = new BufferedReader(new FileReader("D:\\Files\\Java\\01-初步认识Java\\src\\Day_09_文件IO\\buffer.txt"));
            String line;
            System.out.println("最终文件内容如下：");
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }

            br.close();

        } catch (IOException e) {
            System.out.println("写入文件错误");
        }

    }
}
