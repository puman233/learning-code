package 练习.student;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import static 练习.student.Main.list;

public class reStu extends JFrame{
    public reStu() {
        setTitle("修改学生信息");
        setBounds(600, 300, 300, 360);
        setVisible(true);
//        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);

        JTextField  t1;
        JLabel l1,l2;
        JButton b1,b2;

        Container con = getContentPane();

        l1 = new JLabel("学号: ");
        l2=new JLabel("请输入要修改学生的学号");
        l2.setFont(new Font("宋体", Font.PLAIN, 16));
        b1 = new JButton("确认");
        b2 = new JButton("取消");

        t1 = new JTextField(15);

        JPanel p1 = new JPanel();
        JPanel p2 = new JPanel();
        JPanel p5 = new JPanel();
        JPanel p6 = new JPanel();
        JPanel p7 = new JPanel();

        p1.add(l1);
        p1.add(t1);

        p2.add(l2);

        p5.add(b1);

        p6.add(b2);

        p7.add(p2);
        p7.add(p1);
        p7.add(p5);
        p7.add(p6);
        p7.setLayout(new FlowLayout(FlowLayout.CENTER,40,25));
        con.add(p7);

        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String s1 = t1.getText();
                for (int i=0;i<list.size();i++) {//判断学号是否存在
                    student student = list.get(i);
                    if (student.getID().equals(s1)) {
                        new reStuData(i);
                        break;
                    }
                    if (i == list.size() - 1){
                        JOptionPane.showMessageDialog(null, "你输入的学号不存在", "警告", JOptionPane.ERROR_MESSAGE);
                        t1.setText("");
                        return;
                    }
                }


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
class reStuData extends JFrame{
    public reStuData(int i) {
        setTitle("修改学生信息");
        setBounds(600, 300, 300, 360);
        setVisible(true);
//        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);

        JTextField t2,t3,t4;
        JLabel l2,l3,l4;
        JButton b1,b2;

        Container con = getContentPane();

        l2 = new JLabel("姓名: ");
        l3 = new JLabel("性别: ");
        l4 = new JLabel("成绩: ");

        b1 = new JButton("确认");
        b2 = new JButton("取消");


        t2 = new JTextField(15);
        t3 = new JTextField(15);
        t4 = new JTextField(15);

        JPanel p1 = new JPanel();
        JPanel p2 = new JPanel();
        JPanel p3 = new JPanel();
        JPanel p4 = new JPanel();
        JPanel p5 = new JPanel();
        JPanel p6 = new JPanel();
        JPanel p7 = new JPanel();




        p2.add(l2);
        p2.add(t2);

        p3.add(l3);
        p3.add(t3);

        p4.add(l4);
        p4.add(t4);


        p5.add(b1);

        p6.add(b2);

        p7.add(p1);
        p7.add(p2);
        p7.add(p3);
        p7.add(p4);
        p7.add(p5);
        p7.add(p6);
        p7.setLayout(new FlowLayout(FlowLayout.CENTER,40,25));
        con.add(p7);

        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                String s2 = t2.getText();
                String s3 = t3.getText();
                String s4 = t4.getText();
                student student = list.get(i);
                student.setName(s2);
                student.setSex(s3);
                student.setGrade(s4);
                list.set(i, student);
                new Filew().writeStu();
                JOptionPane.showMessageDialog(b1, "修改成功");  //消息对话框
                new reStu();
                dispose();

            }
        });
        b2.addActionListener(new ActionListener(){

            @Override
            public void actionPerformed(ActionEvent e) {
                new reStu();
                dispose();


            }
        });
    }
}
