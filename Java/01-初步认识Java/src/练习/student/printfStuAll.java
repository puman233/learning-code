package 练习.student;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import static 练习.student.Main.list;

public class printfStuAll extends JFrame{
    public printfStuAll() {

        setTitle("遍历学生信息");
        setBounds(600, 300, 300, 360);
        setVisible(true);
//        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);

        JTextArea jt;
        JButton b1,b2;

        Container con = getContentPane();



        b1 = new JButton("确认");
        b2 = new JButton("取消");
        String s[] = new String[list.size()];
        for (int i = 0; i < list.size(); i++) {
            student student = list.get(i);
            s[i]=student.getID()+"   "+student.getName()+"   "+student.getSex()+"   "+student.getGrade();
        }
        String s1="";
        for (int i = 0; i < list.size(); i++) {
            s1=s1+s[i]+"\n";
        }
        jt=new JTextArea(s1,12,20);
//        setBounds(600,300,340,400);
//        jt.setSize(200,200);
        jt.setLineWrap(true);
        JScrollPane jScrollPane = new JScrollPane(jt);
        jScrollPane.setVerticalScrollBarPolicy(
                JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        JPanel p1 = new JPanel();
        JPanel p5 = new JPanel();
        JPanel p6 = new JPanel();
        JPanel p7 = new JPanel();

        p1.add(jScrollPane);

        p5.add(b1);
        p6.add(b2);

        p7.add(p1);
        p7.add(p5);
        p7.add(p6);
        p7.setLayout(new FlowLayout(FlowLayout.CENTER,40,25)); //居中，水平距30，垂直距15
        con.add(p7);
        b1.addActionListener(new ActionListener(){

            @Override
            public void actionPerformed(ActionEvent e) {
                new FileFrame();
                dispose();


            }
        });
        b2.addActionListener(new ActionListener(){

            @Override
            public void actionPerformed(ActionEvent e) {
                new FileFrame();
                dispose();


            }
        });
    }

}