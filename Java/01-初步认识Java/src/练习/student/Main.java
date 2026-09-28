package 练习.student;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

import static 练习.student.Main.fe;
import static 练习.student.Main.list;

public class Main {
    static List<student> list = new ArrayList<student>();
    static String fe=".\\studentData.txt";//文件名
    static {

        File file;
        file = new File(fe);
        if (!file.exists()) {
            try {
                boolean newFile = file.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        //到这里已经成功打开了文件，或者是创建了文件
        //将文件中的数据读入程序
        FileReader fr= null;
        BufferedReader br=null;

        try {
            fr = new FileReader(fe);
            br = new BufferedReader(fr);
            String Line = "";
            while ((Line=br.readLine())!=null){
                String[] s = Line.split("");
                student stu = new student();
                stu.setID(s[0]);
                stu.setName(s[1]);
                stu.setSex(s[2]);
                stu.setGrade(s[3]);
                list.add(stu);
            }
            fr.close();
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {




        new FileFrame();
    }
}
class Filew{ //导出信息到文件类
    public void writeStu(student stu){ //追加写入指定信息
        try {
            FileWriter fw = new FileWriter(fe, true);
            BufferedWriter bw = new BufferedWriter(fw);
            if (!list.isEmpty()){   //bug补丁仅适用于当前方法
                bw.newLine();
            }
            bw.write(stu.getID() + " " +stu.getName() + " " + stu.getSex() + " " +  stu.getGrade());
            bw.close();
            fw.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public void writeStu(){ //全部覆盖写入集合中当前信息
        boolean first=false;
        try {
            FileWriter fw = new FileWriter(fe);
            BufferedWriter bw = new BufferedWriter(fw);

            if (first){ //bug补丁 -改
                bw.newLine();
            }
            first=true;
            for (int i = 0; i <list.size(); i++) {
                student s = list.get(i);
                bw.write(s.getID()+" "+s.getName()+" "+s.getSex()+" "+s.getGrade());
                if (i!=list.size()-1){//预防针
                    bw.newLine();
                }
            }
            bw.close();
            fw.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}